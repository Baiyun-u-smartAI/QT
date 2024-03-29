#include "widget.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QSettings>
#include <QVariant>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <QGridLayout>
#include <QTableWidgetItem>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
extern void ini_test();
extern void xml_create();
extern void json_create();
extern void mysql_test();
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 读ini文件
    QSettings settings("config.ini", QSettings::IniFormat);
    // 提取window组内的配置信息
    settings.beginGroup("window");
    QVariant height = settings.value("height");
    QVariant width = settings.value("width");
    // 判断是否存在height配置信息
    if (height.isNull()||width.isNull()) {
        qDebug() << "height或width配置信息不存在";
    }
    else {
        this->resize(width.toInt(), height.toInt());
    }
    QVariant title = settings.value("title");
    if (title.isNull()) {
        qDebug() << "title配置信息不存在";
    }
    else {
        this->setWindowTitle(title.toString());
    }
    QVariant opacity = settings.value("opacity");
    if (opacity.isNull()) {
        qDebug() << "opacity配置信息不存在";
    }
    else {
        this->setWindowOpacity(opacity.toDouble());
    }
    settings.endGroup();
    // 设置布局为QGridLayout
    QGridLayout *layout = new QGridLayout(this);
    this->setLayout(layout);

    // 设置item表头为 author，title，time
    QStringList header;
    header << "author" << "title" << "time";
    // 创建表格
    item = new QTableWidget(this);
    item->setColumnCount(3);
    item->setHorizontalHeaderLabels(header);
    // 设置字体大小25
    item->setStyleSheet("font-size:25px");
    layout->addWidget(item);
    // xml_read();
    // json_read();
    mysql_test();

}

Widget::~Widget() {}

void ini_test()
{
    // 创建ini文件，存放在当前目录下，内容是软件的配置信息
    QSettings settings("config.ini", QSettings::IniFormat);
    // 创建标签为Software的组
    settings.beginGroup("Software");
    // 写入配置信息
    settings.setValue("name", "MyApp");
    settings.setValue("version", 1);
    settings.endGroup();
    // 创建标签为window的组
    settings.beginGroup("window");
    settings.setValue("height", 1080);
    settings.setValue("width", 1920);
    // 透明度
    settings.setValue("opacity", 1);
    // 标题
    settings.setValue("title", "MyApp");
    settings.endGroup();
    // 保存文件
    settings.sync();
}

void mysql_test()
{
    // 连接到数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost"); // 数据库服务器地址
    db.setDatabaseName("test"); // 数据库名
    db.setUserName("root"); // 用户名
    db.setPassword("password"); // 密码
    // db.setPort(3306); // 端口号

    if (!db.open()) {
        qDebug() << "数据库连接失败：" << db.lastError().text();
        return;
    }
    else qDebug() << "数据库连接成功";

    QSqlQuery query;

    // 创建表
    if (!query.exec("CREATE TABLE IF NOT EXISTS people (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(255), age INT)")) {
        qDebug() << "创建表失败：" << query.lastError().text();
    }


    // 插入数据
    query.prepare("INSERT INTO people (name, age) VALUES (:name, :age)");
    // 使用循环的方式绑定数据，"Lee"和18分别对应:name和:age，"Zhang"和20分别对应:name和:age
    QVariantList names={"Lee", "Zhang"};
    QVariantList ages={18, 20};
    for (int i = 0; i < names.size(); i++) {
        query.bindValue(":name", names.at(i));
        query.bindValue(":age", ages.at(i));
        if (!query.exec()) {
            qDebug() << "插入数据失败：" << query.lastError().text();
        }
        else qDebug() << "插入"<<names.at(i).toString()<<"数据成功";
    }


    // 查询数据
    if (!query.exec("SELECT id, name, age FROM people")) {
        qDebug() << "查询数据失败：" << query.lastError().text();
    }
    while (query.next()) {
        QString name = query.value(1).toString();
        int age = query.value(2).toInt();
        qDebug() << "Name:" << name << "Age:" << age;
    }

    // 更新数据，Zhang的年龄+1
    query.prepare("UPDATE people SET age = age + 1 WHERE name = :name");
    query.bindValue(":name", "Zhang");
    if (!query.exec()) {
        qDebug() << "更新数据失败：" << query.lastError().text();
    }
    else qDebug() << "更新"<< "Zhang" << "数据成功";

    // 查询数据
    if (!query.exec("SELECT id, name, age FROM people")) {
        qDebug() << "查询数据失败：" << query.lastError().text();
    }
    while (query.next()) {
        QString name = query.value(1).toString();
        int age = query.value(2).toInt();
        qDebug() << "Name:" << name << "Age:" << age;
    }

    // 删除Lee的数据
    query.prepare("DELETE FROM people WHERE name = :name");
    query.bindValue(":name", "Lee");
    if (!query.exec()) {
        qDebug() << "删除数据失败：" << query.lastError().text();
    }
    else qDebug() << "删除"<< "Lee" << "数据成功";

    // 查询数据
    if (!query.exec("SELECT id, name, age FROM people")) {
        qDebug() << "查询数据失败：" << query.lastError().text();
    }
    while (query.next()) {
        QString name = query.value(1).toString();
        int age = query.value(2).toInt();
        qDebug() << "Name:" << name << "Age:" << age;
    }
}

/* 创建xml文件，内容如下：
 * <?xml version='1.0' encoding='UTF-8’?>
 * <library>
 * <book time="2013/6/13" id="1">
 * <title>C++ primer</title>
 * <author>Stanley Lippman</author>
 * </book>
 * <book time="2007/5/25" id="2">
 * <title>Thinking in Java</title>
 * <author>Bruce Eckel</author>
 * </book>
 * <book time="1813/1/27" id="3">
 * <title>Pride and Prejudice</title>
 * <author>Jane Austen</author>
 * 	</book>
 * </library>
*/

void xml_create()
{
    QFile file("library.xml");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "打开文件失败";
        return;
    }
    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("library");//写入根元素
    writer.writeStartElement("book");
    writer.writeAttribute("time", "2013/6/13");// 写入属性time
    writer.writeAttribute("id", "1");// 写入属性id
    writer.writeTextElement("title", "C++ primer");// 写入子元素title
    writer.writeTextElement("author", "Stanley Lippman");// 写入子元素author
    writer.writeEndElement();
    writer.writeStartElement("book");
    writer.writeAttribute("time", "2007/5/25");
    writer.writeAttribute("id", "2");
    writer.writeTextElement("title", "Thinking in Java");
    writer.writeTextElement("author", "Bruce Eckel");
    writer.writeEndElement();
    writer.writeStartElement("book");
    writer.writeAttribute("time", "1813/1/27");
    writer.writeAttribute("id", "3");
    writer.writeTextElement("title", "Pride and Prejudice");
    writer.writeTextElement("author", "Jane Austen");
    writer.writeEndElement();
    writer.writeEndElement();//关闭根元素
    writer.writeEndDocument();
    file.close();
}
// 读取library.xml，将里面的所有book元素的title和author元素的内容输出
void Widget::xml_read()
{
    QFile file("library.xml");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "打开文件失败";
        return;
    }
    QXmlStreamReader reader(&file);
    // 找到根元素library
    bool is_library = false;
    while (!reader.atEnd()) { // !reader.atEnd() 判断是否到了文件末尾
        if (reader.isStartElement() && reader.name() == "library") {
            is_library = true;
            break;
        }
        reader.readNext();// 读取下一个元素
    }
    if (!is_library) {
        qDebug() << "未找到根元素library";
        goto END_TAG;
    }
    // 找到book元素
    while (!reader.atEnd()) {
        QString time, title, author;
        if (reader.isStartElement() && reader.name() == "book") {

            // 如果包含属性time和id
            if (!reader.attributes().hasAttribute("time") || !reader.attributes().hasAttribute("id")) {
                qDebug() << "book元素缺少time或id属性";
                goto END_TAG;
            }

            time = reader.attributes().value("time").toString();
            // 输出book元素的属性time和id
            qDebug() << "time:" << time << "id:" << reader.attributes().value("id").toString(); // 输出time和id属性


            // 遍历book元素内部的title和author
            while (!(reader.isEndElement() && reader.name() == "book")) {
                // 如果是title或author的开始元素
                if (reader.isStartElement() && (reader.name() == "title" || reader.name() == "author")) {
                    QString elementText = reader.readElementText();
                    qDebug() << reader.name() << ":" << elementText; // 输出title或author的内容
                    if (reader.name() == "title") {
                        title = elementText;
                    }
                    else {
                        author = elementText;
                    }
                }
                reader.readNext();
            }
        }
        //将time, title, author，写进表格的一行，表头为 author，title，time
        // 如果time, title, author都不为空
        if (time.isEmpty() || title.isEmpty() || author.isEmpty()) {
            reader.readNext(); // 读取下一个元素book
            continue;
        }
        item->insertRow(item->rowCount());
        // 创建三个表格项
        QTableWidgetItem *authorItem = new QTableWidgetItem(author);
        QTableWidgetItem *titleItem = new QTableWidgetItem(title);
        QTableWidgetItem *timeItem = new QTableWidgetItem(time);

        // 将表格项添加到新行，根据表头顺序：author, title, time
        item->setItem(item->rowCount()-1, 0, authorItem); // 第一列是作者
        item->setItem(item->rowCount()-1, 1, titleItem); // 第二列是书名
        item->setItem(item->rowCount()-1, 2, timeItem); // 第三列是时间
        reader.readNext(); // 读取下一个元素book
    }
END_TAG:
    file.close();
}



/* 创建json文件，内容如下：
 * {
 *     "library": {
 *         "books": [
 *             {
 *                 "id": "1",
 *                 "time": "2013/6/13",
 *                 "title": "C++ primer",
 *                 "author": "Stanley Lippman"
 *             },
 *             {
 *                 "id": "2",
 *                 "time": "2007/5/25",
 *                 "title": "Thinking in Java",
 *                 "author": "Bruce Eckel"
 *             },
 *             {
 *                 "id": "3",
 *                 "time": "1813/1/27",
 *                 "title": "Pride and Prejudice",
 *                 "author": "Jane Austen"
 *             }
 *         ]
 *     }
 * }
*/
void json_create()
{
    QFile file("library.json");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "打开文件失败";
        return;
    }
    QJsonObject library;
    QJsonArray books;
    QJsonObject book1;
    book1.insert("id", "1");
    book1.insert("time", "2013/6/13");
    book1.insert("title", "C++ primer");
    book1.insert("author", "Stanley Lippman");
    books.append(book1);// 将book1添加到books数组
    QJsonObject book2;
    book2.insert("id", "2");
    book2.insert("time", "2007/5/25");
    book2.insert("title", "Thinking in Java");
    book2.insert("author", "Bruce Eckel");
    books.append(book2);
    QJsonObject book3;
    book3.insert("id", "3");
    book3.insert("time", "1813/1/27");
    book3.insert("title", "Pride and Prejudice");
    book3.insert("author", "Jane Austen");
    books.append(book3);
    library.insert("books", books); // 将books数组添加到library对象
    QJsonDocument doc(library); // 将library对象转换为json文档
    file.write(doc.toJson()); // 将json文档写入文件
    file.close();
}

// 读取library.json，将里面的所有book元素的title和author元素的内容输出
void Widget::json_read()
{
    QFile file("library.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "打开文件失败";
        return;
    }
    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data); // 从data中读取json
    QJsonObject library = doc.object(); // 转换为json对象
    QJsonArray books = library.value("books").toArray(); // 获取books数组
    for (int i = 0; i < books.size(); i++) {
        QJsonObject book = books.at(i).toObject();
        qDebug() << "id:" << book.value("id").toString();
        qDebug() << "time:" << book.value("time").toString();
        qDebug() << "title:" << book.value("title").toString();
        qDebug() << "author:" << book.value("author").toString();
        // 将id, time, title, author，写进表格的一行，表头为 author，title，time
        item->insertRow(item->rowCount());
        // 创建四个表格项
        QTableWidgetItem *authorItem = new QTableWidgetItem(book.value("author").toString());
        QTableWidgetItem *titleItem = new QTableWidgetItem(book.value("title").toString());
        QTableWidgetItem *timeItem = new QTableWidgetItem(book.value("time").toString());


        // 将表格项添加到新行，根据表头顺序：author, title, time
        item->setItem(item->rowCount()-1, 0, authorItem); // 第一列是作者
        item->setItem(item->rowCount()-1, 1, titleItem); // 第二列是书名
        item->setItem(item->rowCount()-1, 2, timeItem); // 第三列是时间

    }
    file.close();
}

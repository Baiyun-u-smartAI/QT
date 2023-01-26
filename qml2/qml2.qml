import QtQuick 2.15
import QtQuick.Window 2.15
import './'
Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: "鼠标事件"
    Rectangle{
        id: card_border
        width: 303
        height: root.height
        clip: true // 裁剪子部件
        Image{
            id: card
            source: "./2762.jpg"
            height: root.height*2 // 因为原图有两行，所以要缩放成显示大小高度的两倍
            fillMode: Image.PreserveAspectFit
            x: -6*card_border.width
            y: -root.height
        }
        MouseArea{
            anchors.fill: parent
            onEntered: ()=>{
                // 随机剪切出一张牌
                var id_x = 6
                var id_y = 1
                while(id_x === 6 && id_y === 1) { // 确保不是背面图
                    id_x = Math.ceil(Math.random() * 7)-1
                    id_y = Math.ceil(Math.random() * 2)-1
                }

                card.y = -id_y*root.height
                card.x = -id_x*card_border.width

            }
            onExited: ()=>{
                card.y = -root.height
                card.x = -6*card_border.width
            }
            hoverEnabled: true // 激活鼠标事件

        }
    }

}

import QtQuick 2.7
import QtQuick.Window 2.2

Window {
    property int scale_factor: 2
    property int row_height: 40 * scale_factor
    property int image_width: 40 * scale_factor
    property int margin: 5 * scale_factor

    id: window
    visible: true
    width: 375 * scale_factor
    height: 240 * scale_factor
    title: qsTr("Locations Syncing")

    // PRODUCT CODE BELOW THIS LINE

    signal syncActionClicked(string scopeID)
    signal chooseFoldersClicked(string scopeID)

    Component {
        id: siteDelegate

        Rectangle {
            width: window.width
            height: row_height

            Rectangle {
                anchors.fill: parent
                anchors.topMargin: margin

                Image {
                    id: theImage
                    source: imageUrl
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    width: image_width
                }
                Text {
                    id: siteDescription
                    anchors.left: theImage.right
                    anchors.leftMargin: margin
                    text: name
                }
                Text {
                    id: sizeDescription
                    anchors.bottom: parent.bottom
                    anchors.left: theImage.right
                    anchors.leftMargin: margin
                    text: sizeOnDisk
                }
                Text {
                    id: syncAction
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    anchors.rightMargin: margin
                    text: "<a href=\"http://bing.com\">Stop sync</a>"
                    MouseArea {
                        anchors.fill: parent
                        cursorShape: syncAction.hoveredLink ? Qt.PointingHandCursor : Qt.ArrowCursor
                        hoverEnabled: true
                        onClicked: window.syncActionClicked(scopeID)
                    }
                }
                Text {
                    id: chooseFolders
                    anchors.bottom: parent.bottom
                    anchors.right: syncAction.left
                    anchors.rightMargin: margin
                    text: "<a href=\"http://bing.com\">Choose Folders</a>"
                    MouseArea {
                        anchors.fill: parent
                        cursorShape: syncAction.hoveredLink ? Qt.PointingHandCursor : Qt.ArrowCursor
                        hoverEnabled: true
                        onClicked: window.chooseFoldersClicked(scopeID)
                    }
                }
            }
        }
    }

    ListView {
        id: scrollView
        objectName: "scrollView"
        anchors.fill: parent
        model: scrollViewModel
        delegate: siteDelegate
    }

    ListModel {
        id: siteModel
        ListElement {
            name: "OneDrive - Contoso"
            sizeOnDisk: "17 KB"
            imageUrl: "http://cdn.marketplaceimages.windowsphone.com/v8/images/bf05b44c-1e4f-4f31-b8a8-2d42fcf41104?imageType=ws_icon_large"
        }
        ListElement {
            name: "Marketing - Contoso"
            sizeOnDisk: "321 MB"
            imageUrl: "http://cdn.marketplaceimages.windowsphone.com/v8/images/bf05b44c-1e4f-4f31-b8a8-2d42fcf41104?imageType=ws_icon_large"
        }
        ListElement {
            name: "Accounting - Contoso"
            sizeOnDisk: "2.77 GB"
            imageUrl: "http://cdn.marketplaceimages.windowsphone.com/v8/images/bf05b44c-1e4f-4f31-b8a8-2d42fcf41104?imageType=ws_icon_large"
        }
    }
}

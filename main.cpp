#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "locationssyncinglistmodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    LocationsSyncingListModel* model = new LocationsSyncingListModel();
    QQmlContext *ctxt = engine.rootContext();
    ctxt->setContextProperty("scrollViewModel", model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

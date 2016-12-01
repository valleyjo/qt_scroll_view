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

    QObject* rootObject = engine.rootObjects().first();
    QObject::connect(
        rootObject,
        SIGNAL(syncActionClicked(QString)),
        model,
        SLOT(OnSyncActionClicked(QString)));

    QObject::connect(
        rootObject,
        SIGNAL(chooseFoldersClicked(QString)),
        model,
        SLOT(OnChooseFoldersClicked(QString)));

    return app.exec();
}

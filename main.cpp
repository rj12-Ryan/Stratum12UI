#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "TimeProvider.h"
#include "DateProvider.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;


    // Create an instance of TimeProvider and expose it to QML
    TimeProvider* timeProvider = new TimeProvider(&engine);
    engine.rootContext()->setContextProperty("timeProvider", timeProvider);

    // Create an instance of DateProvider and expose it to QML
    DateProvider* dateProvider = new DateProvider(&engine);
    engine.rootContext()->setContextProperty("dateProvider", dateProvider);

    engine.loadFromModule("Stratum12OS", "Main");
    if (engine.rootObjects().isEmpty())
        return -1;


    return app.exec();
}



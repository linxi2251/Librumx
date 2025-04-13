#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSettings>
#include <QFontDatabase>
#include <QIcon>
#include <QQuickStyle>
#include "message_handler.hpp"
#include "settings_service.hpp"
#include "settings_controller.hpp"
void setupGlobalSettings();
void setupFonts();
using namespace presentation::controllers;
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QGuiApplication::setOrganizationName("Librumx-Reader");
    QGuiApplication::setOrganizationDomain("librumxreader.com");
    QGuiApplication::setApplicationName("Librumx");
    QQuickStyle::setStyle(QStringLiteral("Default"));

    QIcon icon(":/logo.ico");
    app.setWindowIcon(icon);

    qInstallMessageHandler(logging::messageHandler);
    setupGlobalSettings();
    setupFonts();


    QQmlApplicationEngine engine;

    SettingsController::s_instance = new SettingsController(new application::services::SettingsService());

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []()
        { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Librumx", "Main");

    return app.exec();
}

void setupGlobalSettings()
{
    QSettings settings;
    QString cfgFile = settings.value("serverHost", QVariant("")).toString();
    if (cfgFile.isEmpty())
        settings.setValue("serverHost", "https://api.librumreader.com");

    QString sslSettings = settings.value("selfHosted", QVariant("")).toString();
    if (sslSettings.isEmpty())
        settings.setValue("selfHosted", "false");
}

void loadFont(const QString &path)
{
    int result = QFontDatabase::addApplicationFont(path);
    if (result == -1)
        qWarning() << QString("Loading font file: %1 failed.").arg(path);
}

void setupFonts()
{
    loadFont(":/resources/fonts/SF-Pro-Display-Bold.otf");
    loadFont(":/resources/fonts/SF-Pro-Display-Medium.otf");
    loadFont(":/resources/fonts/SF-Pro-Display-Regular.otf");
    loadFont(":/resources/fonts/SF-Pro-Display-Semibold.otf");

    QFont defaultFont("SF Pro Display");
    defaultFont.setLetterSpacing(QFont::AbsoluteSpacing, 0.1);
    QGuiApplication::setFont(defaultFont);
}

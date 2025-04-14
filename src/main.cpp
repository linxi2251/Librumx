#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSettings>
#include <QFontDatabase>
#include <QIcon>
#include <QQuickStyle>
#include "message_handler.hpp"
#include "settings_service.hpp"
#include "settings_controller.hpp"
#include "dependency_injection.hpp"
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



    // App Info Stack
    auto *appInfoService =
        config::diConfig().create<application::IAppInfoService *>();
    auto appInfoController =
        std::make_unique<AppInfoController>(appInfoService);
    AppInfoController::s_instance = appInfoController.get();
    // Settings Stack
    auto *settingsService = config::diConfig().create<application::ISettingsService *>();
    auto settingsController = std::make_unique<SettingsController>(settingsService);
    SettingsController::s_instance = settingsController.get();

    QQmlApplicationEngine engine;
    QQuickStyle::setStyle("Basic");
    appInfoController->setQmlApplicationEngine(&engine);

    // Setup translations
    QSettings settings;
    auto storedLanguage = settings.value("language", QVariant("")).toString();
    if(storedLanguage.isEmpty())
    {
        // If no language was specified in the settings, deduce the system language
        const QStringList uiLanguages = QLocale::system().uiLanguages();
        for(const QString& locale : uiLanguages)
        {
            const QString name = QLocale(locale).name();
            if(appInfoController->switchToLanguage(name))
            {
                break;
            }
        }
    }
    else
    {
        appInfoController->switchToLanguage(storedLanguage);
    }

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

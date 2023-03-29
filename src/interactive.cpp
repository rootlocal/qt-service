#include "interactive.h"

InteractiveService::InteractiveService(int argc, char **argv) : QtService<QCoreApplication>(argc, argv, SERVICE_NAME) {
    try {
        setServiceDescription(SERVICE_DESCRIPTION);
        setServiceFlags(QtServiceBase::CanBeSuspended);
    } catch (...) {
        qCritical() << "An unknown error in the constructor";
    }
}

InteractiveService::~InteractiveService() = default;

void InteractiveService::start() {
    try {
        logMessage("Starting Service...", QtServiceBase::Information);
        qDebug() << "Application started";
        qDebug() << QCoreApplication::applicationDirPath();
    } catch (...) {
        qCritical() << "An unknown error in the start";
    }
}

void InteractiveService::stop() {
    try {
        logMessage("Stopping Service...", QtServiceBase::Information);
        qDebug() << "Application stopped";
    } catch (...) {
        qCritical() << "An unknown error in the stop";
    }
}

void InteractiveService::pause() {
    try {
        logMessage("Pause Service...", QtServiceBase::Information);
        qDebug() << "Application pause";
    } catch (...) {
        qCritical() << "An unknown error in the pause";
    }
}

void InteractiveService::resume() {
    try {
        logMessage("resume Service...", QtServiceBase::Information);
        qDebug() << "Application resume";
    } catch (...) {
        qCritical() << "An unknown error in the resume";
    }
}

void InteractiveService::processCommand(int code) {
    try {
        logMessage("processCommand Service...", QtServiceBase::Information);
        qDebug() << "Application processCommand";
    } catch (...) {
        qCritical() << "An unknown error in the processCommand";
    }
}

// sc create "PluginService" binpath="c:\plugin.exe" start=auto
// sc delete "PluginService"
int main(int argc, char **argv) {

#if !defined(Q_OS_WIN)
    // QtService stores service settings in SystemScope, which normally require root privileges.
    // To allow testing this example as non-root, we change the directory of the SystemScope settings file.
    QSettings::setPath(QSettings::NativeFormat, QSettings::SystemScope, QDir::tempPath());
    // qWarning("(Example uses dummy settings file: %s/QtSoftware.conf)", QDir::tempPath().toLatin1().constData());
#endif
    InteractiveService service(argc, argv);

    return service.exec();
}

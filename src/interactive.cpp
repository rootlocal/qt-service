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
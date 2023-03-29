#ifndef INTERACTIVE_H
#define INTERACTIVE_H

#include <QDesktopWidget>
#include <QLabel>
#include <QDir>
#include <QSettings>
#include <QDebug>
#include "qtservice.h"

#define SERVICE_NAME "Qt Interactive Service"
#define SERVICE_DESCRIPTION "A Qt service with user interface."

class InteractiveService : public QtService<QCoreApplication> {

public:
    InteractiveService(int argc, char **argv);

    ~InteractiveService() override;

protected:

    void start() override;

    void stop() override;

    void pause() override;

    void resume() override;

    void processCommand(int code) override;

private:
};

#endif //INTERACTIVE_H

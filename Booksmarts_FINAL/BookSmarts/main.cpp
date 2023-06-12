#include "mainwindow.h"
#include "loginmenu.h"
#include "note.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>
#include <QTimer>
#include <QPainter>
#include <QScreen>
#include <QMessageBox>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    loginMenu loginMenu;
        if (loginMenu.exec() == QDialog::Accepted) {
            MainWindow w;

            QList screens = QGuiApplication::screens();
            QString platform = QGuiApplication::platformName();

    if (screens.size() > 1) { //Sets splashscreen to their second monitor if they have it
        QScreen *screen2 = QGuiApplication::screens().at(1);
        QSize screenGeometry2 = screen2->size();
        int height2 = screenGeometry2.height();
        int width2 = screenGeometry2.width();
        height2 = height2*.15;
        width2 = width2*.15;
        QPixmap SplashImage(width2,height2);
        SplashImage.fill(Qt::white);
        QSplashScreen Screen2(screen2, SplashImage, Qt::WindowStaysOnTopHint);
        Screen2.show();

        Screen2.showMessage("Loading " + platform + " application");
        a.processEvents();

        QTimer::singleShot(5000, &Screen2, SLOT(close()));
        QTimer::singleShot(5000, &w, SLOT(show()));
        return a.exec();
    } else {                //Sets the screen to the primary one if they dont have a second
        QScreen *screen = QGuiApplication::primaryScreen();
        QSize screenGeometry = screen->size();
        int height = screenGeometry.height();
        int width = screenGeometry.width();

        height = height*.15;
        width = width*.15;
        QPixmap SplashImage(width,height);
        SplashImage.fill(Qt::white);
        QSplashScreen Screen(screen, SplashImage, Qt::WindowStaysOnTopHint);
        Screen.show();

        Screen.showMessage("Loading " + platform + " application");
        a.processEvents();

        QTimer::singleShot(5000, &Screen, SLOT(close()));
        QTimer::singleShot(5000, &w, SLOT(show()));
        return a.exec();
    }
        } else {
            QMessageBox::critical(nullptr, "Error", "Login failed");
            return -1;
        }
}

void messageHandler(QtMsgType type, const QMessageLogContext& context, const QString& message)
{
    static QFile logFile("log.log");
    if (!logFile.isOpen()) {
        logFile.open(QFile::WriteOnly | QFile::Text);
    }

    QTextStream logStream(&logFile);
    switch (type) {
    case QtDebugMsg:
        logStream << "Debug: ";
        break;
    case QtInfoMsg:
        logStream << "Info: ";
        break;
    case QtWarningMsg:
        logStream << "Warning: ";
        break;
    case QtCriticalMsg:
        logStream << "Critical: ";
        break;
    case QtFatalMsg:
        logStream << "Fatal: ";
        break;
    }

    logStream << message << Qt::endl;
    logStream.flush();
}

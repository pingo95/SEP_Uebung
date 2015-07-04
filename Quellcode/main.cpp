#include "../Header-Dateien/Mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTranslator translator;
    translator.load("qt_de_DE", QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&translator);
    graphics::MainWindow w;
    w.show();

    return app.exec();
}

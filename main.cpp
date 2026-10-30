#include<QtWidgets/QApplication>
#include "Window.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Window window;
    if (!window.selectIntialFile()) {
        return 0;
    }
    window.show();
    return app.exec();
}
#include "mymainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myMainWindow w;
    w.setWindowTitle("C++源代码单词扫描程序");
    w.show();

    return a.exec();
}

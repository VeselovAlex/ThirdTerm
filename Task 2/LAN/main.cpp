#include <QApplication>
#include "landisplay.h"
#include "filedialog.h"
#include "computertest.h"
#include "lantest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LANDisplay display;
    ComputerTest ctest;
    LANTest ltest;
    QTest::qExec(&ctest);
    QTest::qExec(&ltest);
    display.show();
    return a.exec();
}

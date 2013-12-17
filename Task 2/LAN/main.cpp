#include <QApplication>
#include "landisplay.h"
#include "filedialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LANDisplay display;
    display.show();
    return a.exec();
}

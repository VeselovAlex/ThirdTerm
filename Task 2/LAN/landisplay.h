#ifndef LANDISPLAY_H
#define LANDISPLAY_H

#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "lan.h"
#include "generator.h"
#include "filedialog.h"

class LANDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit LANDisplay();
    ~LANDisplay();
public slots:
    void update(QString cure, QString front, QString infected);
    void stop();
    void loadFileSystemDialog();
private:
    QTextEdit* tedit;
    QPushButton* button;
    LAN* lan;
    Generator* generator;
    FileDialog* dialog;
    QLineEdit* pathField;
    QPushButton* browseBtn;
    QLabel* label;

    void loadLAN();
    void reset();

};

#endif // LANDISPLAY_H

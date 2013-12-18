#include "landisplay.h"

LANDisplay::LANDisplay() :
    QWidget(), tedit(new QTextEdit()), button(new QPushButton("Turn")),
    lan(new LAN), generator(new Generator), pathField(new QLineEdit()),
    browseBtn(new QPushButton("Browse...")), label(new QLabel())
{
    pathField->setEnabled(false);

    reset();

    QObject::connect(button, SIGNAL(clicked()), generator, SLOT(runNextTurn()));
    QObject::connect(browseBtn, SIGNAL(clicked()), this, SLOT(loadFileSystemDialog()));

    QHBoxLayout* fileLayout = new QHBoxLayout();
    fileLayout->addWidget(pathField);
    fileLayout->addWidget(browseBtn);
    QVBoxLayout* layout = new QVBoxLayout();

    this->setGeometry(600, 300, 550, 500);
    this->setLayout(layout);
    layout->addWidget(label);
    layout->addLayout(fileLayout, 2);
    layout->addWidget(tedit);
    layout->addWidget(button, 2);
}

LANDisplay::~LANDisplay()
{
    delete tedit;
    delete lan;
    delete generator;
    delete button;
    delete label;
}

void LANDisplay::update(QString cure, QString front, QString infected)
{
    label->setText("Нажмите Turn для следующего хода.");
    tedit->append("<b><font color = green>CURE:</font></b><br>");
    tedit->append("<font color = blue>" + (cure == "" ? "Empty" : cure) + "</font><br>");
    tedit->append("<b><font color = orange>FRONT:</font></b><br>");
    tedit->append("<font color = blue>" + (front == "" ? "Empty" : front) + "</font><br>");
    tedit->append("<b><font color = red>INFECTED:</font></b><br>");
    tedit->append("<font color = blue>" + (infected == "" ? "Empty" : infected) + "</font><br>");
    tedit->append("----------------------------------------------------------------------");
}

void LANDisplay::stop()
{
    generator->stop();
    tedit->append("<b><u>Stopped</u></b><br>");
    delete lan;
    lan = new LAN();
    reset();
}

void LANDisplay::loadFileSystemDialog()
{
    dialog = new FileDialog();
    QObject::connect(dialog, SIGNAL(fileName(QString)), lan, SLOT(loadDataFromFile(QString)));
    QObject::connect(dialog, SIGNAL(fileName(QString)), pathField, SLOT(setText(QString)));
    QObject::connect(dialog, SIGNAL(fileName(QString)), dialog, SLOT(deleteLater()));
    QObject::connect(dialog, SIGNAL(fileChosen(bool)), button, SLOT(setEnabled(bool)));
    QObject::connect(dialog, SIGNAL(fileChosen(bool)), browseBtn, SLOT(setDisabled(bool)));
    QObject::connect(dialog, SIGNAL(fileChosen(bool)), generator, SLOT(start()));
    dialog->show();
}

void LANDisplay::reset()
{
    button->setEnabled(false);
    browseBtn->setEnabled(true);
    pathField->setText("");
    label->setText("Выберите файл с данными для загрузки...");
    QObject::connect(generator, SIGNAL(nextTurn()), lan, SLOT(turn()));
    QObject::connect(lan, SIGNAL(errorWhileLoading(QString)), label, SLOT(setText(QString)));
    QObject::connect(lan, SIGNAL(stop()), this, SLOT(stop()));
    QObject::connect(lan, SIGNAL(dataChanged(QString,QString,QString)), this, SLOT(update(QString,QString,QString)));
}

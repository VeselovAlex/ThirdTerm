#ifndef LAN_H
#define LAN_H

#include <QObject>
#include <QDebug>
#include <fstream>
#include "computer.h"

class LAN : public QObject
{
    Q_OBJECT
public:
    explicit LAN(QObject *parent = 0);
    QString getCureAsString();
    QString getFrontAsString();
    QString getInfectedAsString();
    void setFirstInfectedComp(Computer* computer);
signals:
    bool stop();
    bool dataChanged(QString, QString, QString);
public slots:
    void addComputer(Computer* computer);
    void addComputer(Computer::OS os);
    void connectComputers(Computer* one, Computer* other);
    void turn();
    void loadDataFromFile(const QString& filename);

private:
    int average;
    QList<Computer*> m_cure;
    QList<Computer*> m_front;
    QList<Computer*> m_infected;

    QString getListAsString(QList<Computer*> & list);
};

#endif // LAN_H

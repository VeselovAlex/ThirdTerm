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
    /**
     * @brief getCureAsString used to get the list of cure computers' names
     * @return QString string of names of cure computers
     */
    QString getCureAsString();
    /**
     * @brief getFrontAsString used to get the list of cure computers' names, which can be infected in the next turn
     * @return QString string of names of cure computers, which can be infected in the next turn
     */
    QString getFrontAsString();
    /**
     * @brief getCureAsString used to get the list of infected computers' names
     * @return QString string of names of infected computers
     */
    QString getInfectedAsString();
    /**
     * @brief setFirstInfectedComp set the first computer in front
     * @param computer first computer by ptr
     */
    void setFirstInfectedComp(Computer* computer);
signals:
    bool stop();
    bool dataChanged(QString, QString, QString);
    bool errorWhileLoading(QString);
public slots:
    /**
     * @brief addComputer add computer to LAN
     * @param computer computer by ptr
     */
    void addComputer(Computer* computer);
    /**
     * @brief addComputer creates a new computer and adds it to LAN
     * @param os new computer os
     */
    void addComputer(Computer::OS os);
    /**
     * @brief connectComputers creates double-sided connection between computers
     * @param one one computer by ptr
     * @param other other computer by ptr
     */
    void connectComputers(Computer* one, Computer* other);
    /**
     * @brief turn process next turn (trying to infect computers in front)
     * After that, emits dataChanged();
     */
    void turn();
    /**
     * @brief loadDataFromFile loads data from text file
     * @param filename path to text file
     */
    void loadDataFromFile(const QString& filename);

private:
    int average;
    QList<Computer*> m_cure;
    QList<Computer*> m_front;
    QList<Computer*> m_infected;

    QString getListAsString(QList<Computer*> & list);
};

#endif // LAN_H

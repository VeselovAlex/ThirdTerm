#include "lan.h"

LAN::LAN(QObject *parent) :
    QObject(parent), average(0)
{
}

QString LAN::getCureAsString()
{
    return getListAsString(m_cure);
}

QString LAN::getFrontAsString()
{
    return getListAsString(m_front);
}

QString LAN::getInfectedAsString()
{
    return getListAsString(m_infected);
}

void LAN::setFirstInfectedComp(Computer *computer)
{
    if (m_cure.contains(computer))
    {
        m_cure.removeAll(computer);
        m_front.append(computer);
    }
}

void LAN::addComputer(Computer *computer)
{
    average++;
    m_cure.append(computer);
}

void LAN::addComputer(Computer::OS os)
{
    QString number;
    number.setNum(average);
    QString name = "Computer_" + number;
    Computer* comp = new Computer(os, name);
    addComputer(comp);
}

void LAN::connectComputers(Computer *one, Computer *other)
{
    bool oneExists = m_cure.contains(one)|| m_front.contains(one) || m_infected.contains(one);
    bool otherExists = m_cure.contains(other)|| m_front.contains(other) || m_infected.contains(other);
    if (oneExists && otherExists)
    {
        one->connectTo(other);
        other->connectTo(one);
    }
}

void LAN::turn()
{
    if (m_front.isEmpty())
    {
        emit stop();
        return;
    }
    foreach (Computer* comp, m_front)
    {
        if (comp->infectCurrent())
        {
            m_front.removeOne(comp);
            m_infected.append(comp);
            QList<Computer*> connectedToCur = comp->connected();
            foreach(Computer* connectedTo, connectedToCur)
            {
                if (m_cure.contains(connectedTo))
                {
                    m_cure.removeOne(connectedTo);
                    m_front.append(connectedTo);
                }
            }
        }
    }
    emit dataChanged(getCureAsString(), getFrontAsString(), getInfectedAsString());
    qDebug() << getCureAsString();
    qDebug() << getFrontAsString();
    qDebug() << getInfectedAsString();
}

void LAN::loadDataFromFile(const QString &filename)
{
    std::ifstream stream;
    stream.open(filename.toStdString().data(), std::ios_base::in);
    if (!stream.is_open())
        qt_assert("File Read Failed", "lan.cpp", 91);

    int averageCount = 0;
    stream >> averageCount;
    qDebug() << averageCount;
    for (int i = 0; i < averageCount; i++)
    {
        int os = 0;
        stream >> os;
        if (os >= OS_COUNT)
            qt_assert("File Read Failed", "lan.cpp", 99);
        qDebug() << os;
        addComputer((Computer::OS)os);
    }
    int firstInfIdx = 0;
    stream >> firstInfIdx;
    qDebug() << firstInfIdx;
    int first = 0;
    int second = 0;
    while (stream.peek() != EOF)
    {
        stream >> first;
        stream >> second;
        qDebug() << first << " " << second;
        if (first > m_cure.length() || second > m_cure.length())
            qt_assert("File Read Failed", "lan.cpp", 109);

        connectComputers(m_cure[first - 1], m_cure[second - 1]);
    }
    setFirstInfectedComp(m_cure[firstInfIdx - 1]);
    stream.close();

    emit dataChanged(getCureAsString(), getFrontAsString(), getInfectedAsString());
}

QString LAN::getListAsString(QList<Computer*> & list)
{
    QString string = "";
    foreach (Computer* comp, list)
        string.append(comp->objectName() + " ");
    return string;
}

#include "test_robots.h"

Test_Robots::Test_Robots(QObject *parent) :
    QObject(parent)
{
}

void Test_Robots::initTestCase()
{
    std::fstream file;
    file.open("matrix5.txt", std::ios_base::in);
    if (!file.is_open())
        qt_assert("File read error ", "test_robots.cpp", 11);

    file >> matrixCount;

    testMatrixArray = new bool**[matrixCount];
    for (int tNum = 0; tNum < matrixCount; tNum++)
    {
        testMatrixArray[tNum] = new bool*[5];
        for (int i = 0; i < 5; i++)
        {
            testMatrixArray[tNum][i] = new bool[5];
            for (int j = 0; j < 5; j++)
                file >> testMatrixArray[tNum][i][j];
        }
    }
    file.close();

    file.open("robots5.txt", std::ios_base::in);
    if (!file.is_open())
        qt_assert("File read error ", "test_robots.cpp", 29);

    file >> robotsCount;

    testRobotsArray = new bool*[robotsCount];
    for (int tNum = 0; tNum < robotsCount; tNum++)
    {
        testRobotsArray[tNum] = new bool[5];
        for (int i = 0; i < 5; i++)
            file >> testRobotsArray[tNum][i];
    }
    file.close();
}

void Test_Robots::testDestroy()
{
    QFETCH(int, nMatrix);
    QFETCH(int, nRobots);
    QFETCH(bool, result);

    bool returned = RobotsGraph::ableToDestroy(testMatrixArray[nMatrix],
                                            testRobotsArray[nRobots], 5);
    QCOMPARE(returned, result);
}

void Test_Robots::testDestroy_data()
{
    std::fstream file;
    file.open("result5.txt", std::ios_base::in);
    if (!file.is_open())
        qt_assert("File read error ", "test_robots.cpp", 51);

    QTest::addColumn<int>("nMatrix");
    QTest::addColumn<int>("nRobots");
    QTest::addColumn<bool>("result");

    bool res = false;
    for (int i = 0; i < matrixCount; i++)
    {
        for (int j = 0; j < robotsCount; j++)
        {
            file >> res;
            QString testName = "TEST_" + QString().setNum(i) +
                                        "_" + QString().setNum(j);
            QTest::newRow(testName.toStdString().data()) << i << j << res;
        }
    }
    file.close();
}

void Test_Robots::cleanupTestCase()
{
    for (int i = 0; i < matrixCount; i++)
    {
        for (int j = 0; j < 5; j++)
            delete[] testMatrixArray[i][j];
        delete[] testMatrixArray[i];
    }

    delete[] testMatrixArray;

    for (int i = 0; i < robotsCount; i++)
        delete[] testRobotsArray[i];
    delete[] testRobotsArray;
}





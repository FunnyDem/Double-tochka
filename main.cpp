#include <QTest>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <QString>

/*
string line = to_string(number);
line = line.substr(0, line.find_last_not_of('0') + 1);
QString result;
result.append(line);
return result;
*/

using namespace std;

class Test: public QObject
{
    Q_OBJECT
public:

    QString toString(double number)
    {
        QString numberLine; numberLine.setNum(number, 'g', 20);
        if(numberLine == "nan" || numberLine == "inf")
        {
            QString letterLine;
            letterLine.setNum(number);
            return letterLine;
        }
        if(numberLine.contains(".", Qt::CaseInsensitive) == false)
        {
            QString intLine;
            intLine.setNum(number);
            intLine.append(".000");
            return intLine;
        }
        else if(numberLine == '0')
        {
            QString nullRes;
            nullRes.setNum(number);
            nullRes.append(".000");
            return nullRes;
        }
        else if(numberLine.contains(".", Qt::CaseInsensitive) == true)
        {
            int counter = 0;
            QString doubleLine;
            QString intLine;
            QString nullLine;
            QString resultLine;
            doubleLine.setNum(number);
            QStringList doubleList = doubleLine.split(".", Qt::SkipEmptyParts);
            doubleLine.clear();
            intLine = doubleList[0];
            doubleLine = doubleList[1];
            for (int i = 0; i < doubleLine.size(); i++)
            {
                if(doubleLine[i] == '0')
                {
                    counter++;
                }
                nullLine.fill('0',counter);
            }
            doubleLine.remove(QChar('0'), Qt::CaseInsensitive);
            doubleLine.truncate(3);
            resultLine.append(intLine);
            resultLine.append(".");
            resultLine.append(nullLine);
            resultLine.append(doubleLine);
            return resultLine;
        }
    }

private slots:

    void testCase1()
    {
        double number = 0.0199999999999;
        QString str = Test::toString(number);
        QCOMPARE(str, QString("0.02"));
    }

    void testCase2()
    {
        double number = 45.00076421;
        QString str = Test::toString(number);
        QCOMPARE(str, QString("45.000764"));
    }

    void testCase3()
    {
        double number = -0.2295269;
        QString str = Test::toString(number);
        QCOMPARE(str, QString("-0.229"));
    }

    void testCase4()
    {
        double number = 8.000076626778888;
        QString str = Test::toString(number);
        QCOMPARE(str, QString("8.0000766"));
    }

    void testCase5()
    {
        double number = -14.00456557;
        QString str = Test::toString(number);
        QCOMPARE(str, QString("-14.00456"));
    }

    void testCase6()
    {
        double number = 0;
        QString str = Test::toString(number);
        QCOMPARE(str, QString("0.000"));
    }

    void testCase7()
    {
        double number = 1000000000;
        QString str = Test::toString(number);
        QCOMPARE(str, QString("1000000000.000"));
    }

    void testCase8()
    {
        double number = -0;
        QString str = Test::toString(number);
        QCOMPARE(str, QString("0.000"));
    }

    void testCase9()
    {
        double number = NAN;
        QString str = Test::toString(number);
        QCOMPARE(str, QString("nan"));
    }
    void testCase10()
    {
        double number = INFINITY;
        QString str = Test::toString(number);
        QCOMPARE(str, QString("inf"));
    }
};
QTEST_MAIN(Test)
#include<main.moc>



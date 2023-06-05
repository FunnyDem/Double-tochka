#include <QObject>
#include <iostream>
#include <string>

class SayingForYou : public QObject
{
    Q_OBJECT
public:
    SayingForYou(QObject *p = Q_NULLPTR) : QObject(p) { }

public slots:
    std::string slotSay (std::string s) { std::cout << "slot: " << s << std::endl; return s; }
};

class SayForMe : public QObject
{
    Q_OBJECT
public:
    SayForMe(QObject *p = Q_NULLPTR) : QObject(p) { }

signals:
    void signalSay(std::string);
};

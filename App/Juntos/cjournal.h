#ifndef CJOURNAL_H
#define CJOURNAL_H

#include <vector>
#include <QString>
#include <QDateTime>

class cJournal
{

    int id;
    QString usr;
    QString usr2;
    QString msg;
    QDateTime date;


public:
    cJournal();
    cJournal(int _id, QString _user , QString _user2 , QString _msg , QDateTime _date);

    QString getUsr() const;
    void setUsr(const QString &value);
    QString getUsr2() const;
    void setUsr2(const QString &value);
    QString getMsg() const;
    void setMsg(const QString &value);
    QDateTime getDate() const;
    void setDate(const QDateTime &value);
    int getId() const;
    void setId(int value);
};

#endif // CJOURNAL_H

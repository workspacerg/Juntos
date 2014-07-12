#ifndef CJOURNAL_H
#define CJOURNAL_H

#include <vector>
#include <QString>
#include <QDateTime>

class cJournal
{

    QString usr;
    QString usr2;
    QString msg;
    QDateTime date;


public:
    cJournal();

    QString getUsr() const;
    void setUsr(const QString &value);
    QString getUsr2() const;
    void setUsr2(const QString &value);
    QString getMsg() const;
    void setMsg(const QString &value);
    QDateTime getDate() const;
    void setDate(const QDateTime &value);
};

#endif // CJOURNAL_H

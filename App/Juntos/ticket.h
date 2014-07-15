#ifndef TICKET_H
#define TICKET_H


#include <QString>



class Ticket
{

    QString idTicket;
    QString nameTicket;
    QString descrTicket;
    QString createName;
    QString createDt;
    QString setUserDate;
    QString endDate;
    QString dev;
    QString etat;



public:

    Ticket();
    Ticket(QString idT, QString nameT, QString descrT , QString createUser , QString dtCreate , QString setUserDt , QString devName , QString etatTk );

    QString getIdTicket() const;
    void setIdTicket(const QString &value);
    QString getNameTicket() const;
    void setNameTicket(const QString &value);
    QString getDescrTicket() const;
    void setDescrTicket(const QString &value);
    QString getCreateName() const;
    void setCreateName(const QString &value);
    QString getCreateDt() const;
    void setCreateDt(const QString &value);

    QString getSetUserDate() const;
    void setSetUserDate(const QString &value);
    QString getDev() const;
    void setDev(const QString &value);
    QString getEtat() const;
    void setEtat(const QString &value);
    QString getEndDate() const;
    void setEndDate(const QString &value);
};

#endif // TICKET_H

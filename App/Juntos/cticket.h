#ifndef CTICKET_H
#define CTICKET_H


#include <QString>
#include <QDateTime>

class CTicket
{

//    QString idTicket;
//    QString idProject;
//  QString nomProjet;
//    QString idCreateBy;
//    QString idAssignTo;
//    QString createName;
//    QString AssignToName;


//    QString nameTicket;
//    QString descrTicket;
//    QString etat;

//    QDateTime createDate;
//    QDateTime assignDate;
//    QDateTime endDate;


public:
    CTicket();
    CTicket(QString idTicket, QString nomPro, QString nameTicket, QString descrTicket,  QString idCreateBy, QString createName, QDateTime createDate,  QDateTime assignDate, QDateTime endDate , QString idAssignTo,  QString AssignToName, QString etat );

//    QString getIdTicket() const;
//    void setIdTicket(const QString &value);
//    QString getIdProject() const;
//    void setIdProject(const QString &value);
//    QString getIdCreateBy() const;
//    void setIdCreateBy(const QString &value);
//    QString getIdAssignTo() const;
//    void setIdAssignTo(const QString &value);
//    QString getNameTicket() const;
//    void setNameTicket(const QString &value);
//    QString getDescrTicket() const;
//    void setDescrTicket(const QString &value);
//    QString getEtat() const;
//    void setEtat(const QString &value);
//    QDateTime getCreateDate() const;
//    void setCreateDate(const QDateTime &value);
//    QDateTime getAssignDate() const;
//    void setAssignDate(const QDateTime &value);
//    QDateTime getEndDate() const;
//    void setEndDate(const QDateTime &value);
//    QString getNomProjet() const;
//    void setNomProjet(const QString &value);

};

#endif // CTICKET_H

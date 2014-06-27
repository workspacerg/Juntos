#ifndef TASK_H
#define TASK_H

#include <QString>

class Task
{

    QString idTask;
    QString titre;
    QString descr;
    QString createur;
    QString dateCreation;
    QString dateModification;
    QString dateFinalisation;
    QString dev;
    QString etat;

public:
    Task();
    Task(QString _id, QString _titre, QString _descr , QString _createur , QString _dev , QString _etat , QString _dtCreation , QString _dtModification , QString _dateFinalisation);

    QString getIdTask() const;
    void setIdTask(const QString &value);
    QString getTitre() const;
    void setTitre(const QString &value);
    QString getDescr() const;
    void setDescr(const QString &value);
    QString getCreateur() const;
    void setCreateur(const QString &value);
    QString getDateCreation() const;
    void setDateCreation(const QString &value);
    QString getDateModification() const;
    void setDateModification(const QString &value);
    QString getDateFinalisation() const;
    void setDateFinalisation(const QString &value);
    QString getDev() const;
    void setDev(const QString &value);
    QString getEtat() const;
    void setEtat(const QString &value);
};

#endif // TASK_H

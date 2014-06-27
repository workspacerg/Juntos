#include "task.h"


QString Task::getIdTask() const
{
    return idTask;
}

void Task::setIdTask(const QString &value)
{
    idTask = value;
}

QString Task::getTitre() const
{
    return titre;
}

void Task::setTitre(const QString &value)
{
    titre = value;
}

QString Task::getDescr() const
{
    return descr;
}

void Task::setDescr(const QString &value)
{
    descr = value;
}

QString Task::getCreateur() const
{
    return createur;
}

void Task::setCreateur(const QString &value)
{
    createur = value;
}

QString Task::getDateCreation() const
{
    return dateCreation;
}

void Task::setDateCreation(const QString &value)
{
    dateCreation = value;
}

QString Task::getDateModification() const
{
    return dateModification;
}

void Task::setDateModification(const QString &value)
{
    dateModification = value;
}

QString Task::getDateFinalisation() const
{
    return dateFinalisation;
}

void Task::setDateFinalisation(const QString &value)
{
    dateFinalisation = value;
}

QString Task::getDev() const
{
    return dev;
}

void Task::setDev(const QString &value)
{
    dev = value;
}

QString Task::getEtat() const
{
    return etat;
}

void Task::setEtat(const QString &value)
{
    etat = value;
}
Task::Task()
{
}

Task::Task(QString _id, QString _titre, QString _descr, QString _createur, QString _dev, QString _etat , QString _dtCreation, QString _dtModification, QString _dateFinalisation)
{

    idTask = _id ;
    titre = _titre ;
    descr = _descr ;
    createur = _createur ;
    dateCreation = _dtCreation ;
    dateModification = _dtModification ;
    dateFinalisation = _dateFinalisation ;
    dev = _dev ;
    etat = _etat ;

}

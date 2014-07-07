#include "test.h"


QString Test::getIdTest() const
{
    return idTest;
}

void Test::setIdTest(const QString &value)
{
    idTest = value;
}

QString Test::getTitre() const
{
    return titre;
}

void Test::setTitre(const QString &value)
{
    titre = value;
}

QString Test::getDescr() const
{
    return descr;
}

void Test::setDescr(const QString &value)
{
    descr = value;
}

QString Test::getParamIn() const
{
    return paramIn;
}

void Test::setParamIn(const QString &value)
{
    paramIn = value;
}

QString Test::getParamOut() const
{
    return paramOut;
}

void Test::setParamOut(const QString &value)
{
    paramOut = value;
}

QString Test::getResultatAttendu() const
{
    return resultatAttendu;
}

void Test::setResultatAttendu(const QString &value)
{
    resultatAttendu = value;
}

QString Test::getValidation() const
{
    return validation;
}

void Test::setValidation(const QString &value)
{
    validation = value;
}
Test::Test(QString _id, QString _titre, QString _descr, QString _paramIn, QString _paramOut, QString _resultatAttendu, QString _validation)
{
    idTest = _id;
    titre = _titre;
    descr = _descr;
    paramIn = _paramIn;
    paramOut =_paramOut;
    resultatAttendu = _resultatAttendu;
    validation = _validation;
}

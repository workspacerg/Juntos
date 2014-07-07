#ifndef TEST_H
#define TEST_H

#include <QString>

class Test
{

    QString idTest;
    QString titre;
    QString descr;
    QString paramIn;
    QString paramOut;
    QString resultatAttendu;
    QString validation;


public:
    Test();
    Test(QString _id , QString _titre , QString _descr , QString _paramIn, QString paramOut , QString _resultatAttendu , QString _validation);
    QString getIdTest() const;
    void setIdTest(const QString &value);
    QString getTitre() const;
    void setTitre(const QString &value);
    QString getDescr() const;
    void setDescr(const QString &value);
    QString getParamIn() const;
    void setParamIn(const QString &value);
    QString getParamOut() const;
    void setParamOut(const QString &value);
    QString getResultatAttendu() const;
    void setResultatAttendu(const QString &value);
    QString getValidation() const;
    void setValidation(const QString &value);
};

#endif // TEST_H

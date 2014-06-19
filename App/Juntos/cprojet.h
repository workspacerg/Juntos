#ifndef CPROJET_H
#define CPROJET_H

#include <QWidget>
#include <QString>

class CProjet
{

public:

    CProjet(QString nom, QString descr);
    CProjet(const CProjet &Source);


    QString getNomProjet() const;
    void setNomProjet(const QString &value);

    QString getDescProjet() const;
    void setDescProjet(const QString &value);




signals:

public slots:

private:

    QString NomProjet       ;
    QString DescProjet      ;


};

#endif // CPROJET_H

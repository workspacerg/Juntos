#ifndef CPROJET_H
#define CPROJET_H

#include <QWidget>
#include <QString>

class CProjet : public QWidget
{
    Q_OBJECT
public:
    explicit CProjet(QWidget *parent = 0);

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

#ifndef UIMESSAGE_H
#define UIMESSAGE_H

#include <QDialog>
#include <vector>
#include "cuser.h"
#include "cmessage.h"
#include "QListWidgetItem"

using namespace std;

namespace Ui {
class uiMessage;
}

class uiMessage : public QDialog
{
    Q_OBJECT

    QString login;
    QString currentUserFocus;

public:
    explicit uiMessage(QWidget *parent = 0);
    ~uiMessage();

    void loadParticipant(vector<cUser>);
    void loadMessage(vector<cMessage>);
    void redColor(QString user);

    QString getLogin() const;
    void setLogin(const QString &value);

    QString getCurrentUserFocus() const;
    void setCurrentUserFocus(const QString &value);

private slots:
    void on_User_itemDoubleClicked(QListWidgetItem *item);



    void on_sendMessage_clicked();

private:
    Ui::uiMessage *ui;

signals:
    void changeListMessage(QString);
    void sendMessageTo(QString,QString);
};

#endif // UIMESSAGE_H

#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <QSystemTrayIcon>


class notification
{

     QSystemTrayIcon * notifyIcon;

public:

    notification();
    void sendNotification(QString titre, QString texte, int temps);

};

#endif // NOTIFICATION_H
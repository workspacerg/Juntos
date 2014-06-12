#include "notification.h"
#include <unistd.h>
notification::notification()
{
    notifyIcon = new QSystemTrayIcon();
    notifyIcon->setIcon(QIcon(":/new/MenuInterface/Ressouces/F-512.png"));
    notifyIcon->show();
}

void notification::sendNotification(QString titre, QString texte, int temps)
{

    notifyIcon->showMessage(titre, texte, QSystemTrayIcon::Information, temps);

}

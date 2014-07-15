#ifndef SETTINGS_H
#define SETTINGS_H
#include <QString>

class Settings
{

	//
	// Property Base de données
	//

		QString dataBaseName ;
	    QString dataBaseType ;
	    QString userBDD ;
	    QString passwordBDD ;
	    

	//
	// Property Utilisateur
	//

	    QString login ;
	    QString password;


public:
    
    Settings();

    bool exist();

    void createSetting();
    void saveSetting();
    void loadSetting();



};

#endif // SETTINGS_H

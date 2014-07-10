#ifndef SHARE_H
#define SHARE_H
#include <QString>

class Share{
    int id;
    int idProject;
    int idCreator;
    QString filename;
    std::string content;

public:
    Share();
    Share(int,int,QString,std::string);
    Share(int,int,int,QString,std::string);

    int getId() const;
    int getIdProject() const;
    int getIdCreator() const;

    QString getFilename() const;
    std::string getContent();
};

#endif // SHARE_H

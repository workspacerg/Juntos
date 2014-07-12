#ifndef SHARE_H
#define SHARE_H
#include <QString>

class Share{
    int id;
    int idProject;
    int idCreator;
    std::string filename;
    QByteArray content;

public:
    Share();
    Share(int,int,std::string,QByteArray);
    Share(int,int,int,std::string,QByteArray);

    int getId() const;
    int getIdProject() const;
    int getIdCreator() const;
    std::string getFilename() const;
    QByteArray getContent() const;
    bool operator <(const Share& s) const
        {
            return id < s.id;
        }
};

#endif // SHARE_H

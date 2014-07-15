#ifndef SHARE_CPP
#define SHARE_CPP
#include "share.h"

Share::Share(int _idProject,int _idUser,std::string _filename,QByteArray _content){
    idProject = _idProject;
    idCreator = _idUser;
    filename = _filename;
    content = _content;
}

Share::Share(int _id, int _idProject, int _idUser, std::string _filename, QByteArray _content){
    id = _id;
    idProject = _idProject;
    idCreator = _idUser;
    filename = _filename;
    content = _content;
}

Share::Share(){

}
int Share::getId() const{
    return id;
}

int Share::getIdCreator() const{
    return idCreator;
}

int Share::getIdProject() const{
    return idProject;
}

std::string Share::getFilename() const{
    return filename;
}

QByteArray Share::getContent() const{
    return content;
}

#endif // SHARE_CPP

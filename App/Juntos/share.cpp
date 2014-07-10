#ifndef SHARE_CPP
#define SHARE_CPP
#include "share.h"

Share::Share(int _idProject,int _idUser,QString _filename,std::string _content){
    idProject = _idProject;
    idCreator = _idUser;
    filename = _filename;
    content = _content;
}

Share::Share(int _id, int _idProject,int _idUser,QString _filename,std::string _content){
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

QString Share::getFilename() const{
    return filename;
}

std::string Share::getContent(){
    return content;
}

#endif // SHARE_CPP

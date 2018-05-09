//
// Created by eduardo on 01/05/18.
//

#ifndef USERMANAGER_USERMANAGER_H
#define USERMANAGER_USERMANAGER_H

#include "DataManager/JSONManager.h"
#include "XMLManager/XMLManager.h"
#include "XMLManager/XMLParts.h"
#include "HashFunct/HashClass.h"
#include "AlphabeticTree/AlphaTree.h"

#include "string"
#include "BTree/BTree.h"

class DataBaseManager {

private:
    JSONManager* JManager = new JSONManager("/home/eduardo/Documents/Datos II/Proyecto 2/Backbone/UserManager/cmake-build-debug/data.json");
    JSONManager* SongManager = new JSONManager("/home/eduardo/Documents/Datos II/Proyecto 2/Backbone/UserManager/cmake-build-debug/songs.json");
    XMLManager* XManager;
    HashClass Hasher;
    AlphaTree UsersTree;
    BTree* songNames = new BTree(3);

public:

    DataBaseManager();
//------------------------------------------Server functions--------------------------------------------------------

    void recieveData(string data);
    void loadTree();
    bool hasFriend(json user, string newFriend);

//------------------------------------------User management---------------------------------------------------------

    string registerUser(string data);
    bool validateUser(string data);
    string friendFunct(string data);

//------------------------------------------Song management---------------------------------------------------------

    string registerSong(string data);
    string searchSongByName(string data);
    string deleteSong(string data);
};


#endif //USERMANAGER_USERMANAGER_H

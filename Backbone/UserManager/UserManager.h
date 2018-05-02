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

class UserManager {

private:
    JSONManager JManager;
    XMLManager* XManager;
    HashClass Hasher;
    AlphaTree UsersTree;

public:

    UserManager();
//------------------------------------------Server functions--------------------------------------------------------

    void recieveData(string data);
    void loadTree();

//-----------------------------------------------User management-------------------------------------------------------
    void registerUser(string data);
    bool validateUser(string data);

};


#endif //USERMANAGER_USERMANAGER_H

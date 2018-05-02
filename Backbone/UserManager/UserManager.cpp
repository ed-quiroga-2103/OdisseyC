//
// Created by eduardo on 01/05/18.
//

#include "UserManager.h"


UserManager::UserManager() {

    JManager.loadJSON();
    this->loadTree();

}

void UserManager::recieveData(string data) {

    string CData = this->XManager->getCDATA(data);
    int opnum = this->XManager->getOpNum(data);

    if(opnum == 0){

        this->registerUser(CData);

    }
    else if(opnum == 1){

        this->validateUser(CData);

    }

}

void UserManager::registerUser(string data) {
    json j = json::parse(data);

    json user = this->JManager.newUser(j["username"], j["pass"], j["name"], j["age"], j["genres"]);

    if(!UsersTree.exists(j["username"])) {

        user["pass"] = Hasher.hash(user["pass"]);

        UsersTree.newNode(j["username"]);

        this->JManager.saveUser(user);

        this->JManager.saveData();

        cout << user.dump();
    }
    else{
        cout << "User exists";
    }

}

bool UserManager::validateUser(string data) {

    json j = json::parse(data);

    if(UsersTree.exists(j["username"])){

        int ind = UsersTree.findNode(j["username"])->getInd();
        json user = JManager.getData()[ind];

        if(user["pass"] == Hasher.hash(j["pass"])){


            cout<< "yes";
            return true;

        }
        else{
            cout<< "no";

            return false;

        }

    }
    else{

        cout<< "User doesnt exists";

    }

    return false;
}

void UserManager::loadTree() {

    json users = JManager.getData();


    for(int i = 0 ; i < users.size(); i++){

        UsersTree.newNode(users[i]["username"]);

    }

}

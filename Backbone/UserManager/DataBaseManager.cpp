//
// Created by eduardo on 01/05/18.
//

#include "DataBaseManager.h"


DataBaseManager::DataBaseManager() {

    JManager->loadJSON();
    SongManager->loadJSON();
    this->loadTree();

}

void DataBaseManager::recieveData(string data) {
    //The XML build is missing from the answering comunication

    string CData = this->XManager->getCDATA(data);
    int opnum = this->XManager->getOpNum(data);

    if(opnum == 0){

        std::cout << this->registerUser(CData);

    }
    else if(opnum == 1){

        this->validateUser(CData);

    }
    else if(opnum == 2){

        this->registerSong(CData);
    }
    else if(opnum == 3){

        std::cout << this->deleteSong(CData);
    }
    else if(opnum == 5){

        std::cout << this->searchSongByName(CData);

    }
    else if(opnum == 9){

        this->friendFunct(CData);

    }

}

string DataBaseManager::registerUser(string data) {

    json j = json::parse(data);

    json user = this->JManager->newUser(j["username"], j["pass"], j["name"], j["age"], j["genres"]);

    if(!UsersTree.exists(j["username"])) {

        user["pass"] = Hasher.hash(user["pass"]);

        UsersTree.newNode(j["username"]);

        this->JManager->saveNewJSON(user);

        this->JManager->saveData();

        return user.dump();
    }
    else{
        return "User exists\n";
    }

}

bool DataBaseManager::validateUser(string data) {

    json j = json::parse(data);

    if(UsersTree.exists(j["username"])){

        int ind = UsersTree.findNode(j["username"])->getInd();
        json user = JManager->getData()[ind];

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

string DataBaseManager::registerSong(string data) {
    json j = json::parse(data);

    //string song, string artist, string album, string lyrics

    json song = this->SongManager->newSong(j["song"], j["artist"], j["album"], j["lyrics"]);

    if(!songNames->search(song["song"])) {

        songNames->insert(song["song"]);

        this->SongManager->saveNewJSON(song);

        this->SongManager->saveData();

    }
    else{
        cout << "Song exists\n";
    }

}

string DataBaseManager::searchSongByName(string data){

    json j = json::parse(data);

    //Only uses song name

    if(songNames->search(j["song"])) {

        json data = SongManager->getData();

        for(int i = 0; i < data.size(); i++){

            json song = data[i];
            if(song["song"] == j["song"]){
                std::cout << "Return ";
                return song.dump();
            }
        }
    }

    else{
        cout << "Song doesnt exists\n";
    }

}

void DataBaseManager::loadTree() {

    json users = JManager->getData();

    json songs = SongManager->getData();


    for(int i = 0 ; i < users.size(); i++){

        UsersTree.newNode(users[i]["username"]);


    }
    for(int i = 0 ; i < songs.size(); i++){

        songNames->insert(songs[i]["song"]);

    }

}

string DataBaseManager::friendFunct(string data) {

    json j = json::parse(data);

    if(UsersTree.exists(j["friend"])){

        TreeNode *node = UsersTree.findNode(j["user"]);

        int ind = node->getInd();

        json user = JManager->getData()[ind];

        if(!hasFriend(user,j["friend"])){

            user["friends"][user["friends"].size()] = j["friend"];

            std::cout << "Friend saved" << endl;

        }

        std::stringstream msg;
        msg << "Hey! Listen to ";
        msg << j["song"];

        user["pending"][user["pending"].size()] = msg.str();

        json data = JManager->getData();

        data[ind] = user;

        JManager->updateData(data);

        JManager->saveData();

        std::cout << "Pending saved"<< endl;

        std::cout << user;

    }

    else std::cout << "User doesnt exists";

}

bool DataBaseManager::hasFriend(json user, string newFriend) {
    string a;
    for(int i = 0; i < user["friends"].size(); i++)

        a = user["friends"][i];

        if(newFriend == a){

            return true;

        }

    return false;
}

string DataBaseManager::deleteSong(string data) {

    json j = json::parse(data);

    json songs = SongManager->getData();

    string current;

    for(int i = 0; i < songs.size(); i++){

        current = songs[i]["song"];

        if(current == j["song"]){

            json data = SongManager->getData();

            data.erase(i);

            SongManager->updateData(data);

            SongManager->saveData();

            std::cout << "Song erased"<< endl;

            return current;

        }

    }

    return "hola";

}
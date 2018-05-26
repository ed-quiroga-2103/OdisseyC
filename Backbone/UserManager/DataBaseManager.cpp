//
// Created by eduardo on 01/05/18.
//

#include "DataBaseManager.h"


DataBaseManager::DataBaseManager() {

    this->JManager->loadJSON();
    this->SongManager->loadJSON();
    this->loadTree();

}

string DataBaseManager::recieveData(string data) {
    //The XML build is missing from the answering comunication

    string CData = this->XManager->getCDATA(data);
    int opnum = this->XManager->getOpNum(data);

    if(opnum == 0){

        return this->registerUser(CData);

    }
    else if(opnum == 1){

        return this->validateUser(CData);

    }
    else if(opnum == 2){

        return this->registerSong(CData);

    }
    else if(opnum == 3){

        return this->deleteSong(CData);
    }
    else if (opnum == 4){

        return this->modifySong(CData);

    }
    else if(opnum == 5){

        return  this->searchSongByName(CData);

    }
    else if(opnum == 9){

        this->addFriend(CData);

    }
    else if (opnum == 10){

        this->recommendSong(CData);

    }
    else if (opnum == 98){

        json j = json::parse(CData);

        int page = j["page"];

        return makeSongStream(page);

    }

}

//Answer: True and registered, or False and modify data DONE
string DataBaseManager::registerUser(string data) {

    json j = json::parse(data);

    json user = this->JManager->newUser(j["username"], j["pass"], j["name"], j["age"], j["genres"]);

    if(!UsersTree.exists(j["username"])) {

        user["pass"] = Hasher.hash(user["pass"]);

        UsersTree.newNode(j["username"]);

        this->JManager->saveNewJSON(user);

        this->JManager->saveData();

        json msg;

        msg["confirmation"] = true;

        return msg.dump();
    }
    else{

        json msg;

        msg["confirmation"] = false;

        return msg.dump();
    }

}

//True or False on log in DONE
string DataBaseManager::validateUser(string data) {

    json j = json::parse(data);

    if(UsersTree.exists(j["username"])){

        int ind = UsersTree.findNode(j["username"])->getInd();
        json user = JManager->getData()[ind];

        if(user["pass"] == Hasher.hash(j["pass"])){



            currentUser = j["username"];

            json msg;

            msg["confirmation"] = 1;

            return msg.dump();
        }
        else{

            json msg;

            msg["confirmation"] = 0;

            return msg.dump();
        }
    }else{

        json msg;

        msg["confirmation"] = 0;

        return msg.dump();

    }
}

//True or False, depends on existance of the song
string DataBaseManager::registerSong(string data) {
    json j = json::parse(data);

    //string song, string artist, string album, string lyrics

    json song = this->SongManager->newSong(j["song"], j["artist"], j["album"], j["lyrics"]);

    if(!songNames->search(song["song"])) {

        songNames->insert(song["song"]);

        this->SongManager->saveNewJSON(song);

        this->SongManager->saveData();

        json msg;

        msg["confirmation"] = 1;

        msg["songs"] = makeSongStream(0);

        return msg.dump();
    }
    else{

        json msg;

        msg["confirmation"] = 0;

        return msg.dump();
    }

}

//Returns Song data
string DataBaseManager::searchSongByName(string data){

    json j = json::parse(data);

    //Only uses song name

    if(songNames->search(j["song"])) {

        json data = SongManager->getData();

        for(int i = 0; i < data.size(); i++){

            json song = data[i];
            if(song["song"] == j["song"]){
                song["confirmation"] = 1;
                return song.dump();
            }
        }
    }

    else{
        json msg;
        msg["confirmation"] = 0;
        return msg.dump();
    }

}

//No Answer
void DataBaseManager::loadTree() {

    json users = JManager->getData();

    json songs = SongManager->getData();


    for(int i = 0 ; i < users.size(); i++){

        UsersTree.newNode(users[i]["username"]);


    }
    for(int i = 0 ; i < songs.size(); i++){

        songNames->insert(songs[i]["song"]);
        albumList.newNode(songs[i]["album"]);
        //artistTree = artistTree->insert(artistTree, songs[i]["artist"]);

    }

}

//------------------------------------------------------------------------------------------------------------------------

//True or False, depending on user friends
string DataBaseManager::recommendSong(string data) {

    json j = json::parse(data);

    if(UsersTree.exists(j["friend"])){

        string a = j["friend"];

        TreeNode *node = UsersTree.findNode(a);

        int ind = node->getInd();

        json user = JManager->getData()[ind];

        std::stringstream msg;
        msg << "Hey! Listen to ";
        msg << j["song"];

        user["pending"][user["pending"].size()] = msg.str();

        json data = JManager->getData();

        data[ind] = user;

        JManager->updateData(data);

        JManager->saveData();

        std::cout << "Pending saved"<< endl;

        return user.dump();

    }

    return "User doesnt exists";

}

//True or False, depending on if friend exists
string DataBaseManager::addFriend(string data) {

    json j = json::parse(data);

    if (UsersTree.exists(j["friend"])) {

        string a = j["user"];

        TreeNode *node = UsersTree.findNode(a);

        int ind = node->getInd();

        json user = JManager->getData()[ind];

        if (!hasFriend(user, j["friend"])) {

            user["friends"][user["friends"].size()] = j["friend"];

            std::cout << "Friend saved" << endl;

        }


        json data = JManager->getData();

        data[ind] = user;

        JManager->updateData(data);

        JManager->saveData();


    }
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

//Confirmation of deletion of song
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

    return "Song doesnt exist";

}

//Confirmation on modification of song and new song data or message of failure
string DataBaseManager::modifySong(string data) {

    json j = json::parse(data);

    json songs = SongManager->getData();

    string current;

    for(int i = 0; i < songs.size(); i++){

        current = songs[i]["song"];

        if(current == j["song"]){

            json data = SongManager->getData();

            json song  = data[i];

            data.erase(i);

            song["song"] = j["newName"];

            song["artist"] = j["artist"];

            song["lyrics"] = j["lyrics"];

            song["album"] = j["album"];

            data[data.size()] = song;

            SongManager->updateData(data);

            SongManager->saveData();
            return "Song updated";
        }

    }

    return "Song doesnt exist";

}

//No answer
string DataBaseManager::makeSongStream(int page){

    std::stringstream stream;
    json songs = SongManager->getData();

    json packedSongs;

    int CERO = 11*page;

    for(int i = CERO; i < (CERO)+11 && i < songs.size(); i++) {

        json song;

        song["song"] = songs[i]["song"];
        song["artist"] = songs[i]["artist"];
        song["album"] = songs[i]["album"];
        song["lyrics"] = songs[i]["lyrics"];

        packedSongs[i-(11*page)] = song;

    }

    return packedSongs.dump();

}

//No answer
string DataBaseManager::makeAnswerXML(int opnum) {

    json users = JManager->getData();

    if(opnum == 0){

    }
    else {
        json JSON;

        JSON["songs"] = makeSongStream(0);

        std::stringstream stream;

        for(int i = 0 ; i < users.size(); i++){

            json current = users[i];

            if(current["username"]==currentUser){
                json json1 = current["pending"];

                if(json1 != NULL) {
                    for (int j = 0; j < current["pending"].size(); j++) {

                        stream << users[i]["pending"][j];
                        stream << "\n";

                    }

                    JSON["pending"] = stream.str();
                }
                else{

                    JSON["pending"] = "No pending messages";

                }
                break;
            }
        }

        XMLDoc doc(0);

        doc.newChild(opnum, JSON.dump());

        return doc.toString();

    }

}


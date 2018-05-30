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

    if(opnum == 0) {

        if (this->registerUser(CData)) {

            return makeAnswerXML(0);

        } else {

            XMLDoc doc(0);

            json j;

            j["confirmation"] = false;

            doc.newChild(opnum, j.dump());

            return doc.toString();

        }
    }


    else if(opnum == 1){

        if (this->validateUser(CData)){


            return makeAnswerXML(1);

        }
        else{

            XMLDoc doc(0);

            json j;

            j["confirmation"] = false;

            doc.newChild(opnum, j.dump());

            return doc.toString();

        }

    }
    else if(opnum == 2){

        if(this->registerSong(CData)){

            return makeAnswerXML(opnum);

        }
        else{

            XMLDoc doc(0);

            json j;

            j["confirmation"] = false;

            doc.newChild(opnum, j.dump());

            return doc.toString();

        }

    }
    else if(opnum == 3){

        if(this->deleteSong(CData)){

            return makeAnswerXML(opnum);

        }
        else{

            XMLDoc doc(0);

            json j;

            j["confirmation"] = false;

            doc.newChild(opnum, j.dump());

            return doc.toString();

        }
    }
    else if (opnum == 4){

        return this->modifySong(CData);

    }
    else if(opnum == 5){

        return  this->searchSongByName(CData);

    }
    else if(opnum == 9){

        if(this->addFriend(CData)){

            return makeAnswerXML(opnum);

        }
        else{

            XMLDoc doc(0);

            json j;

            j["confirmation"] = false;

            doc.newChild(opnum, j.dump());

            return doc.toString();

        }
    }
    else if (opnum == 10) {

        this->recommendSong(CData);

    }
    else if (opnum == 11){

        if(this->songScore(CData)){

            XMLDoc doc(0);

            json j;

            j["confirmation"] = true;

            doc.newChild(opnum, j.dump());

            return doc.toString();

            return j.dump();

        }else{
            XMLDoc doc(0);

            json j;

            j["confirmation"] = false;

            doc.newChild(opnum, j.dump());

            return doc.toString();


        }

    }
    else if (opnum == 98){

        json j = json::parse(CData);

        int page = j["page"];

        json ret;

        ret["songs"] = makeSongStream(page);

        XMLDoc doc(0);

        ret["confirmation"] = true;

        doc.newChild(opnum, ret.dump());

        return doc.toString();
    }

}

//Answer: True and registered, or False and modify data DONE
bool DataBaseManager::registerUser(string data) {

    json j = json::parse(data);

    json user = this->JManager->newUser(j["username"], j["pass"], j["name"], j["age"], j["genres"]);

    if(!UsersTree.exists(j["username"])) {

        user["pass"] = Hasher.hash(user["pass"]);
        user["email"] = j["email"];

        UsersTree.newNode(j["username"]);

        this->JManager->saveNewJSON(user);

        this->JManager->saveData();

        return true;
    }
    else{

        return false;
    }

}

//True or False on log in DONE
bool DataBaseManager::validateUser(string data) {

    json j = json::parse(data);

    if(UsersTree.exists(j["username"])){

        int ind = UsersTree.findNode(j["username"])->getInd();
        json user = JManager->getData()[ind];

        if(user["pass"] == Hasher.hash(j["pass"])){



            currentUser = j["username"];

            json msg;

            msg["confirmation"] = 1;

            return true;
        }
        else{

            json msg;

            msg["confirmation"] = 0;

            return false;
        }
    }else{

        json msg;

        msg["confirmation"] = 0;

        return false;

    }
}

//True or False, depends on existance of the song
bool DataBaseManager::registerSong(string data) {
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

        return true;
    }
    else{

        json msg;

        msg["confirmation"] = 0;

        return false;
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
bool DataBaseManager::recommendSong(string data) {

    json j = json::parse(data);

    if(UsersTree.exists(j["friend"])){

        currentUser = j["user"];

        string a = j["friend"];

        TreeNode *node = UsersTree.findNode(a);

        int ind = node->getInd();

        json user = JManager->getData()[ind];

        std::stringstream msg;
        msg << "Hey! Listen to ";
        msg << j["song"];

        json pend;

        pend["song"] = j["song"];
        pend["user"] = j["friend"];
        pend["friend"] = j["friend"];

        user["pending"][user["pending"].size()] = pend;

        json data = JManager->getData();

        data[ind] = user;

        JManager->updateData(data);

        JManager->saveData();

        std::cout << "Pending saved"<< endl;

        return true;

    }

    return false;

}

//True or False, depending on if friend exists
bool DataBaseManager::addFriend(string data) {

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
bool DataBaseManager::deleteSong(string data) {

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

            return true;

        }

    }

    return false;

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
json DataBaseManager::makeSongStream(int page){

    std::stringstream stream;
    json songs = SongManager->getData();

    json packedSongs;

    int CERO = 11*page;
    if(songs.size() == 0){

        return json::array();

    }else {
        for (int i = CERO; i < (CERO) + 11 && i < songs.size(); i++) {

            json song;

            song["song"] = songs[i]["song"];
            song["artist"] = songs[i]["artist"];
            song["album"] = songs[i]["album"];
            song["lyrics"] = songs[i]["lyrics"];

            packedSongs[i - (11 * page)] = song;

        }
    }
    return packedSongs;

}

//No answer
string DataBaseManager::makeAnswerXML(int opnum) {

    json users = JManager->getData();

    if(opnum == 0){
        json JSON;
        JSON["confirmation"] = true;
        XMLDoc doc(0);

        doc.newChild(opnum, JSON.dump());

        return doc.toString();

    }
    else if (opnum == 1) {
        json JSON;

        JSON["songs"] = makeSongStream(0);

        for(int i = 0 ; i < users.size(); i++){

            json current = users[i];

            if(current["username"]==currentUser){
                json user;

                user["name"] = current["name"];
                user["username"] = current["username"];
                user["age"] = current["age"];
                user["email"] = current["email"];

                JSON["user"] = user;

                JSON["pending"] = user["pending"];

                JSON["confirmation"] = true;

                break;
            }
        }

        XMLDoc doc(0);

        doc.newChild(opnum, JSON.dump());

        return doc.toString();
    }
    else if (opnum == 2){

        json JSON;
        JSON["confirmation"] = true;
        JSON["songs"] = makeSongStream(0);
        XMLDoc doc(0);

        doc.newChild(opnum, JSON.dump());

        return doc.toString();

    }
    else if (opnum == 3){

        json JSON;
        JSON["confirmation"] = true;
        JSON["songs"] = makeSongStream(0);
        XMLDoc doc(0);

        doc.newChild(opnum, JSON.dump());

        return doc.toString();

    }else if (opnum == 9){

        json JSON;
        JSON["confirmation"] = true;

        int ind = UsersTree.findNode(currentUser)->getInd();

        json user = JManager->getData()[ind];

        JSON["friends"] = user["friends"];
        XMLDoc doc(0);

        doc.newChild(opnum, JSON.dump());

        return doc.toString();

    }


}

bool DataBaseManager::songScore(string data) {

    json j = json::parse(data);

    json songs = SongManager->getData();

    string current;

    for(int i = 0; i < songs.size(); i++){

        current = songs[i]["song"];

        if(current == j["song"]){

            json data = SongManager->getData();

            json song  = data[i];

            data.erase(i);

            song["rating"] = j["rate"];

            data[data.size()] = song;

            SongManager->updateData(data);

            SongManager->saveData();
            return true;
        }

    }
    return false;

}



//
// Created by eduardo on 28/04/18.
//

#include <fstream>
#include "JSONManager.h"

JSONManager::JSONManager(string path) {

    this->PATH = path;

}

json JSONManager::newUser(string username, string pass, string name, string age, string genres) {

    json user;

    user["username"] = username;
    user["pass"] = pass;
    user["name"] = name;
    user["age"] = age;
    user["genres"] = genres;
    user["friends"] = {};
    user["pending"] = {};

    return user;
}

json JSONManager::newSong(string song, string artist, string album, string lyrics) {

    json newJson;

    newJson["song"] = song;
    newJson["artist"] = artist;
    newJson["album"] = album;
    newJson["lyrics"] = lyrics;

    return newJson;

}

void JSONManager::loadJSON() {
    if(this->dataExists()) {
        std::ifstream i(PATH);

        i >> this->data;
    }
    else{

        std::ofstream outfile (PATH);
    }
}

void JSONManager::saveNewJSON(json newData) {

    this->data[this->data.size()] = newData;

}

json JSONManager::getData(){
    return data;
}

void JSONManager::saveData() {

    std::ofstream out;

    remove(PATH.c_str());

    out.open (PATH, std::ofstream::in);

    out.write(this->data.dump().c_str(),this->data.dump().size());

    out.close();

}

bool JSONManager::dataExists() {

    std::ifstream infile(PATH);
    return infile.good();


}

void JSONManager::updateData(json data) {

    this->data = data;

}

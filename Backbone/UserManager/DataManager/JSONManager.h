    //
// Created by eduardo on 28/04/18.
//

#ifndef JSONMANAGER_JSONMANAGER_H
#define JSONMANAGER_JSONMANAGER_H

#include "string"
#include "nlohmann/json.hpp"
#include "iostream"

using json = nlohmann::json;
using string = std::string;
class JSONManager {
private:
    json data;
    string PATH;
    bool exists = false;
public:
    JSONManager(string path);

    bool dataExists();

    json getData();

    json newUser(string username, string pass, string name, string age, string genres);

    json newSong(string song, string artist, string album, string lyrics);

    void loadJSON();

    void saveNewJSON(json newData);

    void saveData();

};


#endif //JSONMANAGER_JSONMANAGER_H

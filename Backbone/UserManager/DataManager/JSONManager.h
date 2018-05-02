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
    string PATH = "/home/eduardo/Documents/Datos II/Proyecto 2/Backbone/DataManager/cmake-build-debug/data.json";
    bool exists = false;
public:
    bool dataExists();

    json getData();

    json newUser(string username, string pass, string name, string age, string genres);

    void loadJSON();

    void saveUser(json user);

    void saveData();

};


#endif //JSONMANAGER_JSONMANAGER_H

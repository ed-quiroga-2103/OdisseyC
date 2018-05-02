//
// Created by eduardo on 28/04/18.
//

#include <fstream>
#include "JSONManager.h"

json JSONManager::newUser(string username, string pass, string name, string age, string genres) {

    json user;

    user["username"] = username;
    user["pass"] = pass;
    user["name"] = name;
    user["age"] = age;
    user["genres"] = genres;

    return user;
}

void JSONManager::loadJSON() {
    if(this->dataExists()) {
        std::ifstream i("data.json");

        i >> this->data;
    }
    else{

        std::ofstream outfile ("data.json");

    }

}

void JSONManager::saveUser(json user) {

    this->data[this->data.size()] = user;

}

json JSONManager::getData(){
    return data;
}

void JSONManager::saveData() {

    std::ofstream out;

    out.open ("data.json", std::ofstream::in);

    out.write(this->data.dump().c_str(),this->data.dump().size());

    out.close();

}
bool JSONManager::dataExists() {

    std::ifstream infile("data.json");
    return infile.good();


}
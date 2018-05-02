#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include "JSONManager.h"

using json = nlohmann::json;

int main() {

    JSONManager man;

    man.loadJSON();

    json user1 = man.newUser("mj230899","contrasena", "Maria", "18", "Dancehall");

    json user2 = man.newUser("equiroga","holi", "Eduardo", "19", "Jazz");

    man.saveUser(user1);
    man.saveUser(user2);

    json j = man.getData();

    man.saveData();


    return 0;
}
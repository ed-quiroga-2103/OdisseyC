#include <iostream>
#include "UserManager.h"
#include "XMLManager/XMLParts.h"
#include "XMLManager/XMLManager.h"


using json = nlohmann::json;

int main() {


    UserManager um;

    XMLDoc doc(0);

    json j;

    j["username"] = "asdf";
    j["pass"] = "hola";
    j["name"] = "Eduardo";
    j["age"] = "19";
    j["genres"] = "hip hop";


    doc.newChild(0, j.dump());

    XMLDoc dec(0);
    dec.newChild(1, j.dump());


    um.recieveData(doc.toString());
    um.recieveData(dec.toString());






    return 0;
}
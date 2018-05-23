#include <iostream>
#include "DataBaseManager.h"
#include "XMLManager/XMLParts.h"
#include "XMLManager/XMLManager.h"
#include "BTree/BTree.h"
#include "string"

using json = nlohmann::json;
using string = std::string;

int main() {

    DataBaseManager* um = new DataBaseManager();


    //std::cout << um->makeSongStream();


    JSONManager jm("");

    XMLDoc doc(0);

    json j;

    j["username"] = "user";
    j["pass"] = "user";


    doc.newChild(1, j.dump());
/*
    XMLDoc dec(0);
    JSONManager jm("");
    json song = jm.newSong(" Angels", "RHCP", "The Getaway", "ASDF");
    dec.newChild(5, song.dump());
*/



      um->recieveData(doc.toString());
    //um.recieveData(dec.toString());



    return 0;
}



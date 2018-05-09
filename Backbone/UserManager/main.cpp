#include <iostream>
#include "DataBaseManager.h"
#include "XMLManager/XMLParts.h"
#include "XMLManager/XMLManager.h"
#include "BTree/BTree.h"
#include "string"

using json = nlohmann::json;
using string = std::string;

int main() {

    DataBaseManager um;

    JSONManager jm("");

    XMLDoc doc(0);

    json j;

    j = jm.newSong("Goodbye Angels","sdf","asdfa","asdfa");

    doc.newChild(2, j.dump());
/*
    XMLDoc dec(0);
    JSONManager jm("");
    json song = jm.newSong(" Angels", "RHCP", "The Getaway", "ASDF");
    dec.newChild(5, song.dump());
*/



    um.recieveData(doc.toString());
    //um.recieveData(dec.toString());




    return 0;
}



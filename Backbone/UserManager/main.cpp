#include <iostream>
#include "DataBaseManager.h"
#include "XMLManager/XMLParts.h"
#include "XMLManager/XMLManager.h"
#include "BTree/BTree.h"
#include "string"
#include "GenericServer/mainServer.h"

using json = nlohmann::json;
using string = std::string;





int main() {

    //mainServer server(8081);
    //server.runServer();


    XMLManager xml;

    string a = xml.newXMLDoc(1,"user")->toString();
    std::cout << a;


    DataBaseManager* um = new DataBaseManager();

    JSONManager jm("");

    json j = jm.newSong("song","asdf","asf","asdf");

    XMLDoc doc(0);

    doc.newChild(3, j.dump());

    std::cout << um->recieveData(doc.toString());




    return 0;
}
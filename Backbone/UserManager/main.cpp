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

    mainServer server(8081);
/*
    XMLManager xml;

    string a = xml.newXMLDoc(1,"user")->toString();
    std::cout << a;
*/
    server.runServer();
/*
    DataBaseManager* um = new DataBaseManager();

    JSONManager jm("");

    json j;

    j["pass"] = "user";
    j["username"] = "user";


    XMLDoc doc(0);

    doc.newChild(1, j.dump());

    std::cout << um->recieveData(doc.toString());
*/



    return 0;
}
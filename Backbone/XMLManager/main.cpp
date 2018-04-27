#include <iostream>
#include "pugixml.hpp"
#include "string"
using document = pugi::xml_document;
using string = std::string;
int main() {

    string PATH = "/home/eduardo/Documents/Datos II/Proyecto 2/Backbone/XMLManager/example.xml";

    document doc;

    pugi::xml_parse_result result = doc.load_file(PATH.c_str());

    if (result){
        std::cout << doc.child("books").child("book").child("name").text().get() << std::endl;
    }
    else{
            std::cout << result.description() << std::endl;
    }

    return 0;
}
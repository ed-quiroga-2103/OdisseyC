//
// Created by eduardo on 28/04/18.
//

#include <iostream>
#include <sstream>
#include "XMLParts.h"
#include "pugixml.hpp"
#include "string"

XMLDoc::XMLDoc(){}
XMLDoc::XMLDoc(int check) {

    pugi::xml_node parent = this->append_child("oddata");

    pugi::xml_node data = parent.append_child("data");

}

void XMLDoc::newChild(int opnum, string data) {

    pugi::xml_node parent = this->child("oddata").child("data");

    pugi::xml_node opchild = parent.append_child("opnum");
    opchild.append_child(pugi::node_pcdata).set_value(std::to_string(opnum).c_str());

    pugi::xml_node cdata = parent.append_child("CData");
    cdata.append_child(pugi::node_cdata).set_value(data.c_str());

}

void XMLDoc::saveXML(string name) {

    this->save_file(name.c_str());

}

string XMLDoc::toString() {

    this->print(writer);

    return writer.print();

}





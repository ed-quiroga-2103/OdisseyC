//
// Created by eduardo on 28/04/18.
//

#include <iostream>
#include "XMLManager.h"

XMLDoc* XMLManager::newXMLDoc(int opnum, string CDATA) {
    XMLDoc* doc = new XMLDoc(0);
    doc->newChild(opnum, CDATA);
    return doc;
}

void XMLManager::saveXML(XMLDoc doc, string name) {
    doc.saveXML(name);
    return;
}

string XMLManager::getCDATA(string str) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(str.c_str());
    return doc.child("oddata").child("data").child("CData").text().get();
}

int XMLManager::getOpNum(string str) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(str.c_str());
    return std::stoi(doc.child("oddata").child("data").child("opnum").text().get());
}

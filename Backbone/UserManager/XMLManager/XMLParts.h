//
// Created by eduardo on 28/04/18.
//

#ifndef XMLMANAGER_XMLPARTS_H
#define XMLMANAGER_XMLPARTS_H

#include "pugixml.hpp"
#include "string"
using string = std::string;

class XMLWriter: public pugi::xml_writer{

public:
    std::string result;

    virtual void write(const void* data, size_t size)
    {
        result.append(static_cast<const char*>(data), size);
    }

    string print(){ return result; }

};

class XMLDoc: public pugi::xml_document {
private:
    XMLWriter writer;

public:
    XMLDoc();
    XMLDoc(int check);

    void newChild(int opnum, string data);

    void saveXML(string name);

    string toString();
};

#endif //XMLMANAGER_XMLPARTS_H

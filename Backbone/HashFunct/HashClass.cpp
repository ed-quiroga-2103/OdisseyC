//
// Created by eduardo on 26/04/18.
//

#include <sstream>
#include "HashClass.h"

int HashClass::search(char chr) {

    for(int i = 0; i < characters.size(); i++){

        if(characters[i] == chr){

            return i;

        }

    }

}

string HashClass::hash(string in) {

    std::stringstream res;

    for(int i = 0; i < in.size(); i++){

        int ind = search(in[i]);

        res << hashing[ind];

    }

    return res.str();

}

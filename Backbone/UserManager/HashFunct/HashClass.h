//
// Created by eduardo on 26/04/18.
//

#ifndef PROYECTO_2_HASHCLASS_H
#define PROYECTO_2_HASHCLASS_H

#include "string"
#include "../DataStructs/DataStructures.h"

using string = std::string;

class HashClass {

private:
    int hashing[64]={3801,9201,1827,4083,5212,3211,4581,3522,3980,7093,2772,
            5928,6136,3743,2039,4050,7413,7643,8101,4600,4690,5138,2390,2458,
            6887,6340,3094,1070,8484,3275,2631,3719,4003,6129,3294,7135,8253,
            6691,8595,7783,6385,7458,3437,2970,6966,1261,2706,1964,6839,8003
            ,7659,3820,7788,5549,1079,3339,8576,5510,8633,5066,5036,5016,4524,9777};
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

public:

    string hash(string in);
    int search(char chr);

};


#endif //PROYECTO_2_HASHCLASS_H

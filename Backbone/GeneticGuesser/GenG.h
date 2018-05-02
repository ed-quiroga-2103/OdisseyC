//
// Created by eduardo on 28/04/18.
//

#ifndef GENETICGUESSER_GENG_H
#define GENETICGUESSER_GENG_H

#include "../DataStructs/DataStructures.h"
#include "Random.h"
#include "string"

class GenG {

private:
    Random random;

    int inds[10];

    static const int size = 10;

    SingleList<string> selWords;

    int fitness[size] = {0,0,0,0,0,0,0,0,0,0};

    string word[33] = {"","01","02","03","04","05","06","07","08","09","10",
                    "11","21","23","41","51","61","71","81","91","31","00",
                     "51","52","54","53","56","57","59","90","99","65","78"};
public:

    void selectPop();

    void evalPop();

    void mutate();



};


#endif //GENETICGUESSER_GENG_H

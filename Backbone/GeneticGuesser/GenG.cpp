//
// Created by eduardo on 28/04/18.
//

#include <sstream>
#include "GenG.h"

void GenG::selectPop() {

    for(int i = 0; i < size; i++){

        inds[i] = random.randIntArr(size,2,33)[i*4];

    }
    for(int i = 0; i < size; i++) {
        selWords.newNode(this->word[inds[i]]);
    }

}

void GenG::evalPop() {


    for(int i = 0; i < size; i++){

        string fit;

        cout<< selWords[i] << endl;
        cout<< "Match: " << endl;
        cin >> fit;
        if(fit == "a"){

            fitness[i] = 1;
            cout << "Fitted" << endl;

        }
        if(fit == "b"){

            cout << "Done" << endl;
            break;

        }



    }
    for(int i = 0; i < size; i++){

        cout<< "Word: " << selWords[i] << ", Fitness: " << fitness[i] << endl;

    }

}
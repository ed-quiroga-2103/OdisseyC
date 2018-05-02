#include <iostream>
#include "Random.h"
#include "cstdlib"
#include <ctime>
#include "unistd.h"
#include "../DataStructs/DataStructures.h"
#include "GenG.h"


int main() {

    Random random;

    GenG g;

    g.selectPop();
    g.evalPop();

    return 0;




}
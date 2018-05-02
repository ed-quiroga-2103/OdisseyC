#include <iostream>
#include "../DataStructs/DataStructures.h"
#include "string"
#include "HashClass.h"

int main() {

    SingleList<string> sl;

    HashClass hc;

    sl.newNode(hc.hash("mainises666"));

    string a = hc.hash("mainises666");

    string b = sl[0];

    bool c = a == b;

    std::cout << a << "\n" << b << endl;

    std::cout << c;

    return 0;
}
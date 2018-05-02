//
// Created by eduardo on 27/04/18.
//

#include "Random.h"
#include <ctime>
#include <cmath>
#include "cstdlib"

int Random::randInt(int digNum) {

    srand(time(0));

    return this->sliceNum(rand(),digNum);


}
int Random::randInt(int max, int digNum) {

    int res = this->randInt(digNum);

    while(res > max){

        res = this->randInt(digNum);

    }

    return res;
}

int Random::length(int num) {

    if (num == 0) {
        return 0;
    } else {

        return 1 + this->length(floor(num/10));

    }
}

int Random::sliceNum(int num, int digNum) {

    if(digNum >= this->length(num)){

        return num;

    }
    else{

        return this->sliceNum(floor(num/10), digNum);

    }
}

int* Random::randIntArr(int len, int digNum) {

    int* arr = (int*) malloc(sizeof(int)*len);

    srand(time(0));

    int ind = 0;

   while(ind < len){

        int num = this->sliceNum(rand(),digNum);

        if(this->length(num)<=digNum) {
            if (num < pow(10, digNum)) {
                *(arr + sizeof(int) * ind) = num;
                ind++;
            }
        }
    }

    return arr;

}

int* Random::randIntArr(int len, int digNum, int max) {

    int* arr = (int*) malloc(sizeof(int)*len);

    srand(time(0));

    int ind = 0;

    while(ind < len){

        int num = this->sliceNum(rand(),digNum);

        bool check = this->checkList(ind, num, arr);

        if(this->length(num)<=digNum && check) {
            if (num < max) {
                *(arr + sizeof(int) * ind) = num;
                ind++;
            }
        }
    }

    return arr;

}

bool Random::checkList(int ind, int num, int *arr) {

    for(int i = 0; i < ind; i++){

        if(arr[i] == num){
            return false;
        }

    }

    return true;
}
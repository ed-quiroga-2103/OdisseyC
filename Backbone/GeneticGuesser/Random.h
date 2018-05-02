//
// Created by eduardo on 27/04/18.
//

#ifndef GENETICGUESSER_RANDOM_H
#define GENETICGUESSER_RANDOM_H



class Random {

public:

    int randInt(int digNum);

    int randInt(int max, int digNum);

    bool randBool();

    int* randIntArr(int len, int digNum);

    int* randIntArr(int len, int digNum, int max);

    bool checkList(int ind, int num, int* arr);

private:

    int sliceNum(int num, int digNum);

    int length(int num);


};


#endif //GENETICGUESSER_RANDOM_H

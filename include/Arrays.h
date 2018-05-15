#include <iostream>
#include <fstream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include "Peak.h"
#ifndef ARRAYS_H
#define ARRAYS_H

using namespace std;

class Arrays
{
    public:
        Arrays();
        virtual ~Arrays();

        void passFromFile();
        void quickSort(int left, int right);
        void sortBySecond();
        void putInIDs();
        vector<int> getFirst(){return first;}
        vector<int> getSecond(){return second;}
        vector<Peak> getIDs(){return IDs;}
        Peak getIDs(int i){return IDs[i];}


    protected:

    private:
        int value;
        bool decider=1;
        vector<Peak> IDs;
        vector<int> first,second;
};

#endif // ARRAYS_H

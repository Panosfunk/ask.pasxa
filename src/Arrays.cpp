#include "Arrays.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

Arrays::Arrays()
{
    //ctor
}
void Arrays::passFromFile()
{
    int value;
    bool decider=1;
    fstream myFile;
    myFile.open("testInput8.txt");
    //myFile.open("input.txt");
        if(myFile){
            while(myFile >> value) {
                if(decider){
                    first.push_back(value);
                    decider=0;
                }
                else{
                    second.push_back(value);
                    decider=1;
                }
            }
            myFile.close();
        }
        else{
            cout << "Unable to open" << endl;
        }
}
void Arrays::quickSort(int left, int right)
{
    int i = left, j = right;
    int tmp1,tmp2;
    int pivot = first[(left + right) / 2];
    /* partition */
    while (i <= j) {
        while (first[i] < pivot)
              i++;
        while (first[j] > pivot)
              j--;
        if (i <= j) {
              tmp1 = first[i];
              first[i] = first[j];
              first[j] = tmp1;

              tmp2 = second[i];
              second[i]=second[j];
              second[j]=tmp2;
              i++;
              j--;
        }
    };
    /* recursion */
    if (left < j)
        quickSort(left, j);
    if (i < right)
        quickSort(i, right);
}
void Arrays::sortBySecond()
{
    int part=first[0];
    int start=0,finish=0;
    for(int i=1; i<first.size(); i++){
        while(first[i]==part){
            i++;
        }
        part=first[i];
        finish=i-1;
        quickSort(start, finish);
        start=i;
    }
}
void Arrays::putInIDs()
{
    Peak a;
    int part=first[0];
    a.x=first[0];
    a.Neighbors.push_back(second[0]);
    IDs.push_back(a);
    for(int i=1; i<first.size(); i++){
        if(first[i]!=a.x){
            Peak b;
            a.x=first[i];
            a.Neighbors.push_back(second[i]);
            b.x=first[i];
            b.Neighbors.push_back(second[i]);
            IDs.push_back(b);
        }
        else{
            IDs[IDs.size()-1].Neighbors.push_back(second[i]);
        }
    }
}

Arrays::~Arrays()
{
    //dtor
}

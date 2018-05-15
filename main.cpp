#include <iostream>
#include <fstream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <math.h>

#include "Peak.h"
#include "Arrays.h"

using namespace std;

void quickSort(vector<int> &first, vector<int> &second, int left, int right) {
//      int i = left, j = right;
//      int tmp1,tmp2;
//      int pivot = first[(left + right) / 2];
//      /* partition */
//      while (i <= j) {
//            while (first[i] < pivot)
//                  i++;
//            while (first[j] > pivot)
//                  j--;
//            if (i <= j) {
//                  tmp1 = first[i];
//                  first[i] = first[j];
//                  first[j] = tmp1;
//
//                  tmp2 = second[i];
//                  second[i]=second[j];
//                  second[j]=tmp2;
//                  i++;
//                  j--;
//            }
//      };
//      /* recursion */
//      if (left < j)
//            quickSort(first, second, left, j);
//      if (i < right)
//            quickSort(first, second, i, right);
}
//sorts all the elements from the second vector that have the same value on the respective position on the first vector
void sortBySecond(vector<int> &first,vector<int> &second)
{
//    int part=first[0];
//    int start=0,finish=0;
//    for(int i=1; i<first.size(); i++){
//        while(first[i]==part){
//            i++;
//        }
//        part=first[i];
//        finish=i-1;
//        quickSort(second, first, start, finish);
//        start=i;
//    }
}
//creates the IDS vector which is the final.
void putInVectors(vector<int> &first,vector<int> &second, vector<Peak> &IDS)
{
//    Peak a;
//    int part=first[0];
//    a.x=first[0];
//    a.Neighbors.push_back(second[0]);
//    IDS.push_back(a);
//    for(int i=1; i<first.size(); i++){
//        if(first[i]!=a.x){
//            Peak b;
//            a.x=first[i];
//            a.Neighbors.push_back(second[i]);
//            b.x=first[i];
//            b.Neighbors.push_back(second[i]);
//            IDS.push_back(b);
//        }
//        else{
//            IDS[IDS.size()-1].Neighbors.push_back(second[i]);
//        }
//    }
}
void passFromFile(vector<int> &first, vector<int> &second)
{
//    int value;
//    bool decider=1;
//    fstream myFile;
//    myFile.open("input.txt");
//    //myFile.open("input.txt");
//        if(myFile){
//            while(myFile >> value) {
//                if(decider){
//                    first.push_back(value);
//                    decider=0;
//                }
//                else{
//                    second.push_back(value);
//                    decider=1;
//                }
//            }
//            myFile.close();
//        }
//        else{
//            cout << "Unable to open" << endl;
//        }
        ///////////////////////////////////////START OF ARRAYS WAY/////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////END OF ARRAYS WAY////////////////////////////////////////////////////
}

int main()
{
//    int value;
//    bool decider=1;
//    int a;
//    vector<Peak> IDS;
//    vector<int> first,second;
    /*
    fstream myFile;
    cout << "1. Array \n2. AVL Tree \n3.Hash Table" << endl;
    cin>>a;

    myFile.open("input.txt");
    //myFile.open("input.txt");
    if(a==1){
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
        }*/
        ///////////////////////////////////////START OF ARRAYS WAY/////////////////////////////////////////////////////////////////////
        Arrays a;
        a.passFromFile();
        a.quickSort(0, a.getFirst().size()-1);
        a.sortBySecond();
        a.putInIDs();
        //Printing every Node and its Neighbors at its right
        for(int i=0; i<a.getIDs().size(); i++){
            cout << "Node: " << a.getIDs(i).x << "  Neighbors: " ;
            for(int j=0; j<a.getIDs(i).Neighbors.size(); j++){
                cout << a.getIDs(i).Neighbors[j] << " " ;
            }
            cout << endl;
        }
        ////////////////////////////////////////END OF ARRAYS WAY////////////////////////////////////////////////////
    //}

    return 0;

}

/*
vector<int> FindNeighbors(int x, vector<int> first, vector<int> second)
{
    vector<int> Neighbors;
    int i,j=0;
    int DisDeSpot;
    for(i=0; first[i]<=x; i++){
        if(first[i]==x){
            Neighbors.push_back(second[i]);
            //DisDeSpot=i;
        }
    }
    /*
    while(first[DisDeSpot]==x){
        Neighbors.push_back(second[DisDeSpot]);
        DisDeSpot++;
    }
    return Neighbors;
}
*/

/*
ostream &operator<<(ostream &mystream, Point3D &p)
{
 mystream<<p.x<<", "<<p.y<<", "<<p.z<<endl;
 return mystream;
}
*/

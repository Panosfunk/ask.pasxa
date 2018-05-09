#include <iostream>
#include <fstream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <math.h>

#include "Peak.h"

using namespace std;

// C program for insertion sort


/* Function to sort an array using insertion sort*/
void insertionSort(vector<int> &Neighbors)
{
    int i, key, j;
    int n=Neighbors.size();
    for (i = 1; i < n; i++)
    {
        key = Neighbors[i];
        j = i-1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && Neighbors[j] > key)
        {
            Neighbors[j+1] = Neighbors[j];
            j = j-1;
        }
        Neighbors[j+1] = key;
    }
}

// A utility function to print an array of size n
void printArray(vector<int> Neighbors)
{
    int i;
    int n=Neighbors.size();
    for (i=0; i < n; i++)
        printf("%d ", Neighbors[i]);
    printf("\n");
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
bool check(int value, vector<Peak> IDS)
{
    int i;
    for(i=0; i<IDS.size(); i++){
        if(value==IDS[i].getX())
            return true;
    }
    return false;
}

int find_position(int value, vector<Peak> IDS)
{
    int i;
    for(i=0; i<IDS.size(); i++){
        if(value==IDS[i].getX())
            return i;
    }
}


int main()
{
    //char a;
    //double input,total=0.0;
    //cout << "Give a number between 1-3\n" << "1.Array\n" << "2.AVL Tree\n" << "3.Hash Table\n" << endl;
    //cin >> a;
    int i=0,j,position,counter=0;
    bool decider=1,value_is_in_vector=false;
    double value;

    vector<int> first,second;
    vector<Peak> IDS;

    fstream myFile;

    myFile.open("input.txt");
    if(myFile){
    cout << "At least im doing sth" <<endl;
        while(myFile >> value){
            cout << i << " ";
                position=-1;
                if(decider){
                    if(!(value_is_in_vector=check(value,IDS))){
                        IDS.push_back(value);
                        decider=0;
                    }
                    else{
                        position=find_position(value,IDS);
                        myFile>>value;
                        IDS[position].Neighbors.push_back(value);
                    }
                }
                else{
                    if(position<0){
                        IDS[counter].Neighbors.push_back(value);
                        decider=1;
                        counter++;
                    }
                    else{
                        IDS[position].Neighbors.push_back(value);
                        decider=1;
                        counter++;
                    }
                }
        i++;
        }
    cout << "Passing values is done" << endl;
        myFile.close();
    }else{
        cout << "Unable to open" << endl;
    }
    for(i=0; i<IDS.size(); i++){
        insertionSort(IDS[i].Neighbors);
       // printArray(IDS[i].Neighbors);
    }
    cout << "InsertionSort is done" << endl;

    //Printing every Node and its Neighbors at its right
    /*for(i=0; i<IDS.size(); i++){
        cout << "Node: " << IDS[i].getX() << " Neighbors: " ;
        for(j=0; j<IDS[i].Neighbors.size(); j++){
            cout << IDS[i].Neighbors[j] << " " ;
        }
        cout << endl;
    }*/

    cout << "Node: " << IDS[0].getX() << " Neighbors: " ;
    for(j=0; j<IDS[0].Neighbors.size(); j++){
        cout << IDS[0].Neighbors[j] << " " ;
    }
    cout << endl;

    return 0;
}


/*
ostream &operator<<(ostream &mystream, Point3D &p)
{
 mystream<<p.x<<", "<<p.y<<", "<<p.z<<endl;
 return mystream;
}

*/



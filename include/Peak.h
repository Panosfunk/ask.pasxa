#ifndef PEAK_H
#define PEAK_H
#include <vector>

using namespace std;

class Peak
{
    public:
        Peak();
        Peak(int val);

        void setX(int val){x=val;}
        int getX(){return x;}

        virtual ~Peak();
        vector<int> Edges;
        vector<int> Neighbors;
        int x;

    protected:

    private:
};

#endif // PEAK_H

//passing from file the old way
/*
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
*/

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

    protected:

    private:
        int x;
};

#endif // PEAK_H

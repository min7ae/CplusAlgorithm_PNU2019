#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _Point{
    int x;
    int y;

    _Point(int _x, int _y)
    :x(_x), y(_y) {}
} Point;

bool comp(Point pa, Point pb){
    if(pa.x == pb.x){
        return pa.y < pb.y;
    } else {
        return pa.x < pb.x;
    }
}

int main()
{
    ifstream ifs;
    ofstream ofs;

    ifs.open("sampleData3/1.inp");
    ofs.open("battery.out");

    int n, z;
    ifs >> n >> z;
    vector<Point> p;
    vector<int> lines;

    for(int i = 0; i < n; i++)
    {
        int x, y;
        ifs >> x >> y;
        p.push_back(Point(x, y));
    } 
    sort(p.begin(), p.end(), comp);
    
    for(int i = 0; i < n; i++)
    {
        cout << p[i].x << " " <<  p[i].y << endl;
    } 
    
    ifs.close();
    ofs.close();
    return 0;
}
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

bool compXY(Point pa, Point pb){
    return pow(pa.x,2)+pow(pa.y,2) < pow(pb.x,2)+pow(pb.y,2);
}

bool chklines(vector<Point> p, int w){
    bool ret = 0;

    return ret;
}

int main()
{
    ifstream ifs;
    ofstream ofs;

    ifs.open("1.inp");
    ofs.open("battery.out");

    int n, z;
    ifs >> n >> z;
    vector<Point> p;

    for(int i = 0; i < n; i++)
    {
        int x, y;
        ifs >> x >> y;
        p.push_back(Point(x, y));
    } 
    
    // 원점과 가장 가까운 순으로 정렬
    sort(p.begin(), p.end(), compXY);



    ifs.close();
    ofs.close();
    return 0;
}
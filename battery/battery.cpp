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
    return sqrt(pow(pa.x,2)+pow(pa.y,2)) < sqrt(pow(pb.x,2)+pow(pb.y,2));
}

// bool compY(Point pa, Point pb){
//     if(pa.y == pb.y){
//         return pa.x < pb.x;
//     } else {
//         return pa.y < pb.y;
//     }
// }

// bool compX(Point pa, Point pb){
//     if(pa.x == pb.x){
//         return pa.y < pb.y;
//     } else {
//         return pa.x < pb.x;
//     }
// }

int chklines(vector<Point> p, int w){
    int ret = 0;
    vector<double> lines;

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
    vector<double> lines;

    for(int i = 0; i < n; i++)
    {
        int x, y;
        ifs >> x >> y;
        p.push_back(Point(x, y));
        // lines.push_back(sqrt(pow(x,2)+pow(y,2)));
    } 

    

    ifs.close();
    ofs.close();
    return 0;
}
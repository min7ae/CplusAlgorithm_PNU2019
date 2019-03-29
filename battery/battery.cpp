#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct _Point{
    int x;
    int y;

    _Point(int _x, int _y)
    :x(_x), y(_y) {}
} Point;

// pa와 pb 사이 거리 제곱 비교
bool compXY(Point pa, Point pb){
    return pow(pa.x,2)+pow(pa.y,2) < pow(pb.x,2)+pow(pb.y,2);
}

// 두 점 사이의 거리 제곱
int lengthP(Point pa, Point pb = Point(0,0)){
    return pow(pa.x-pb.x,2) + pow(pa.y-pb.y,2);
}

// 길이 w 보다 p사이의 거리 제곱이 큰게 존재한다면, true
bool isExist(vector<Point> p, int w){
    vector<Point> candidate;
    candidate.push_back(p[0]);
    candidate.push_back(p[1]);
    int ans = lengthP(p[0], p[1]);
    for (int i=2; i<p.size(); i++) {
        Point now = p[i];
        for (auto it = candidate.begin(); it!=candidate.end(); ) {
            auto p = *it;
            int x = now.x - p.x;
            if (x*x > ans) {
                it = candidate.erase(it);
            } else {
                int d = lengthP(now, p);
                if (d < ans) {
                    ans = d;
                }
                it++;
            }
        }
        candidate.push_back(now);
    }
    if (w < lengthP(candidate[0], candidate[1])) {
        return false;
    } else {
        return true;
    }
}
    

int main()
{
    ifstream ifs;
    ofstream ofs;

    ifs.open("battery.inp");
    ofs.open("battery.out");

    int n, z;
    ifs >> n >> z;
    vector<Point> p;
    
    // 구하려는 길이
    int w_last = pow(z, 2);
    int w_first = 0;
    int w = w_last-w_first;
    // printf("%d", w);
    for(int i = 0; i < n; i++)
    {
        int x, y;
        ifs >> x >> y;
        p.push_back(Point(x, y));
    } 
    
    // 원점과 가장 가까운 순으로 정렬
    sort(p.begin(), p.end(), compXY);
     
    /*
        if isExist가 true면 w = w/2
        else w = w*2;
    */ 
   bool flag = false;
   int lastw = w;
   while(!flag){
        if(isExist(p, w)){
           w_last =(w_first + w_last)/2;
        } else {
           w_first =(w_first + w_last)/2;
        } 
        w = w_last - w_first;
        // w가 바뀌지 않았다면, while문 탈출
        if(lastw == w){
            flag = true;
        }
        lastw = w;
        // printf("%d ", w);
   }
    cout << w << endl;
    ifs.close();
    ofs.close();
    return 0;
}
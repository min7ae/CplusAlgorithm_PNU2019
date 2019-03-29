#include <iostream>
#include "oil.h"
using namespace std;

int main(){
    initial();
    int N = oil_size();

    // start, last, cen
    // chk: 0, 1, 2
    int s, l, cen, chk;
    s = 0; l = N-1; cen = (s+l)/2;

    //answer
    int i = 0;
    int j = N-1;

    oil_report(i, j);
    return 0;
}
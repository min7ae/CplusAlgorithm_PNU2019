#include <iostream>
#include "oil.h"
using namespace std;

int chkCases(int s, int l){
    int cen = (s+l)/2;
    int Left = observe(s, cen);
    int Right = observe(cen+1, l);

    /*
    case
     Left|Right 
    00000|00110
    00000|11111
    00111|11100
    11111|00000
    01100|00000
    */

   if (Left == 0 && Right == 2) return 1;
   else if (Left == 0 && Right == 1) return 2;
   else if (Left == 2 && Right == 2) return 3;
   else if (Left == 1 && Right == 0) return 4;
   else if (Left == 2 && Right == 0) return 5;

   return -1; // ??
}


int main(){
    initial();
    int N = oil_size();

    // start, last, cen
    int s, l, cen, chk;
    s = 0; l = N-1; cen = (s+l)/2;







    // oil_report(i, j);
    return 0;
}
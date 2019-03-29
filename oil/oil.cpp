#include <iostream>
#include "oil.h"
using namespace std;

int chkCasesofL(int s, int l){
    printf("caseL: %d %d\n", s, l);
    int cen = (s+l)/2;
    printf("center: %d\n", cen);
    int Left = observe(s, cen);
    int Right = observe(cen+1, l);

    /*
    case
     Left|Right 
    00000|00111
    00000|11111
    00111|11111
    11111|11111
    */

   if (Left == 0) {
       if (Right == 2) return 1;
       else if (Right == 1) return 2;
   } else if(Left == 2){
       return 3;
   } 
   // this is answer
   return 4;
}

int chkCasesofR(int s, int l){
    printf("caseR: %d %d\n", s, l);
    int cen = (s+l)/2;
    printf("center: %d\n", cen);
    int Left = observe(s, cen);
    int Right = observe(cen+1, l);

    /*
    case
     Left|Right 
    11100|00000
    11111|00000
    11111|11000
    11111|11111
    */

   if (Left == 2 && Right == 0) return 1;
   else if (Left == 1 && Right == 0) return 2;
   else if (Left == 1 && Right == 2) return 3;
   
    return 4;
}

int chkCases(int s, int l){
    printf("cases: %d %d\n", s, l);
    int cen = (s+l)/2;
    printf("center: %d\n", cen);
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
    11111|11111
    */

   if (Left == 0 && Right == 2) return 1;
   else if (Left == 0 && Right == 1) return 2;
   else if (Left == 2 && Right == 2) return 3;
   else if (Left == 1 && Right == 0) return 4;
   else if (Left == 2 && Right == 0) return 5;

   // this is answer
   // 11111|11111
   return -1;
}


int main(){
    initial();
    int N = oil_size();

    // start, last, cen
    int s, l, cen, chk;
    s = 0; l = N-1; cen = (s+l)/2;

    // make 2|2
    while(true){
        int chk = chkCases(s, l);
        cen = (s+l)/2;
        if (chk == 3) {
            break;
        }
        if (chk == 1) {
            s = cen + 1;
        } else if (chk == 2) {
            oil_report(cen+1, l);
        } else if (chk == 4) {
            oil_report(s, cen);
        } else if (chk == 5) {
            l = cen;
        }
    }
    printf("ifind2|2\n");

    // 2|2라고 가정하면,
    //000111|11000
    // LLast|RFirst
    int LLast = cen;
    int RFirst = cen+1;

    // find begin point
    while(true){
        int chk = chkCasesofL(s, LLast);
        cen = (s+LLast)/2;
        if (chk == 4) {
            break;
        } 
        switch (chk)
        {
            case 1:
                s = cen;
                break;
            case 2:
                s = cen+1;
                break;
            case 3:
                LLast = cen;
                break;
            default:
                break;
        }
    }
    printf("ifindleft: %d\n", s);
    // find end point
    while(true){
        int chk = chkCasesofR(RFirst, l);
        cen = (RFirst + l)/2;
        if (chk == 4) {
            break;
        } 
        switch (chk)
        {
            case 1:
                l = cen;
                break;
            case 2:
                l = cen;
                break;
            case 3:
                RFirst = cen+1;
                break;
            default:
                break;
        }
    }
    printf("ifindright: %d\n", l);
    
    oil_report(s, l);
    return 0;
}
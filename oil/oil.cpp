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

int findAnswer(int s, int l){
    int cen = (s+l)/2;
    int chk = chkCases(s, l);
    if (chk == -1) {
        return -1;
    }
    
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

    switch (chk)
    {
        case 1:
            s = cen+1; cen = (s+l)/2;
            break;

        case 2:
            // find LeftAnswer
            return -2; 
            break;

        case 3:
            s = cen+1; cen = (s+l)/2;
            break;

        case 4:
            l = cen; 
            break;

        case 5:
            l = cen; cen = (s+l)/2;
            break;
    
        default:
            break;
    }
}


int main(){
    initial();
    int N = oil_size();

    // start, last, cen
    int s, l, cen, chk;
    s = 0; l = N-1; cen = (s+l)/2;

    while(true){
        chk = chkCases(s, l);
        if (chk == -1) {
            break;
        }
        
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

        switch (chk)
        {
            case 1:
                s = cen+1; cen = (s+l)/2;
                break;

            case 2:
                s = cen+1; 
                break;

            case 3:
                findAnswer(s, cen);
                break;

            case 4:
                l = cen; 
                break;

            case 5:
                l = cen; cen = (s+l)/2;
                break;
        
            default:
                break;
        }
    }
    
    oil_report(s, l);
    return 0;
}
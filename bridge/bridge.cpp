#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

double FindLow(int A[], int B[], int P[], double t){
    double S[3] = {0.0, };
    double Length = 0.0;

    for(int i = 0; i < 3; i++){  
        S[i] = (t * B[i] + (1.0-t) * A[i]);
        Length += pow ( S[i] - (double)P[i] , 2.0 );
    }
    
    Length = sqrt(Length);
    return Length;
}

int main(){
    ifstream ifs;
    ofstream ofs;
    
    //Point
    int A[3] = {0, };
    int B[3] = {0, };
    int P[3] = {0, };
    double S[3] = {0.0, };

    ifs.open("bridge.inp");
    ofs.open("bridge.out");

    //T
    // 0.0 <= T <= 1.0
    double MaxT = 1.0;
    double MinT = 0.0;

    // CurT=현재커서 preCurT=과거커서, f(T) - f(preT)의 차이가 0.0001 이하일때까지,
    double CurT = 0.0;
    double preCurT = 0.0;
    double diff = 1.0;

    if( ifs.is_open() ){
        for(int i = 0; i < 3; i++){
            ifs >> A[i];
        }
        for(int i = 0; i < 3; i++){
            ifs >> B[i];
        }
        for(int i = 0; i < 3; i++){
            ifs >> P[i];
        }

        int cnt = 0;

        // 현재커서 과거커서, f(T) - f(preT)차이가 0.0001 이하일때까지,
        while(abs(diff) > 0.0001){
            if (FindLow(A,B,P,MaxT) > FindLow(A,B,P,MinT)) {
                // Max가 크다면 Max을 뒤로
                MaxT = (MaxT + MinT )/2.0;
                CurT = MaxT;
            } else {
                // Min이 크다면 Min을 뒤로
                MinT = (MinT + MaxT )/2.0;
                CurT = MinT;
            }

            // 처음이면통과
            if (cnt != 0) {
                diff = FindLow(A,B,P,CurT) - FindLow(A,B,P,preCurT);
            }

            preCurT = CurT;
            cnt++;
        }

        // printf("%d", (int)ceil(FindLow(A,B,P,CurT)));
        ofs << (int)ceil(FindLow(A,B,P,CurT));
        ofs.close();
        ifs.close();
        
    }

    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int chkpalin(string str){
    /* origin str과 reversed str을 만들고 */
    string ori = str;
    string rev = str;
    reverse(rev.begin(), rev.end());

    /* 홀수 경우와 짝수 경우를 비교 */
    // if(str.length() % 2 == 0){
        
    // } else {

    // }

}

int main()
{
    cout << "hello";
    ifstream ifs;
    ifs.open("1.inp");

    while(!ifs.eof()){
        int n;
        ifs >> n;
        for(int i = 0; i < n; i++)
        {
            string chkingString;
            cout << chkingString;
            // cout << chkpalin(chkingString);
        }
    }
    ifs.close();
    return 0;
}
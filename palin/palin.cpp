#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int chkpalin(string str){
    int ret = 3;
    /* origin str과 reversed str을 만들고 */
    string ori = str;
    string rev = str;
    reverse(rev.begin(), rev.end());

    /* 홀수 경우와 짝수 경우를 비교 */
    int difN = 0;
    if(str.length() % 2 != 0){
        // cur를 0부터 갯수만큼
        for(int cur = 0; cur < str.length(); cur++)
        {   // 다른거 있을때마다 dif++
            if (ori.at(cur) != rev.at(cur)) {
                difN++;
            }
        }
        // 하나도 없다면 
        if (difN == 0) {
            // palin
            ret = 1;
        // 두개라면 (한 세트가 틀림)
        } else if (difN == 2){
            ret = 2;
        } // 아니면 ret == 3
    // 짝수라면
    } else {
        if (str.compare(rev) == 0) {
            ret = 1;
        } else {
            // center 가 중앙 바로 전 문자일 때,
            int center = str.length()/2;
            string makedstr = str.substr(center);
            string makedrev = rev.substr(center + 1);
            int cur = 0;
            for(cur = 0; cur < center; cur++)
            {
                if (makedstr.at(cur) != makedrev.at(cur)) {
                    break;
                }
            }
            string remakedrev = rev.substr(cur) + rev.substr(cur+1, center);
            bool isPalin = true;
            for(cur = 0; cur < center; cur++)
            {
                if (makedstr.at(cur) != remakedrev.at(cur)) {
                    isPalin = false;
                }
            }
            
            if (isPalin) {
                ret = 2;
            }
        }
    }
    return ret;
}

int main()
{
    string fName = "sampleData_palin/3.inp";
    string oName = "1.out";

    ifstream openFile(fName.data());
    // ofstream writeFile(oName.data());
    if(openFile.is_open()){

        string line;
        getline(openFile, line);
        int n = stoi(line);
        for(int i = 0; i < n; i++)
        {
            getline(openFile, line);
            cout << chkpalin(line) << "\n";
        }
        openFile.close();
    }

    return 0;
}
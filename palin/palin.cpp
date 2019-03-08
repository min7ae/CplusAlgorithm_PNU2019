#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int chkpalin(string str){
    int ret = 3;
    int center = str.length() / 2;
    int last = str.length() - 1;
    // 홀수라면
    if (str.length() % 2 != 0) {
        int cur = 0;
        while( ( str.at(cur) == str.at(last - cur) ) || center == cur ){
            cur++;
        }
        if (center == cur) {
            ret = 1;
        } else {
            
        }
        

        
    // 짝수라면
    } else {
    
    }
    // ori 순서
    string ori = str.substr(center);

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
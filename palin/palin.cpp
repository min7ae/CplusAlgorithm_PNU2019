#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int chkpalin(string str){
    int ret = 1;
    // center를 chk
    int center = str.length() / 2;
    // curser
    int cur = 0;
    // cur를 증가시키는데, center에 도달할때까지
    // !짝수 홀수때 경우가 똑같을까? 
    while(cur != center){
        if(str.at(cur) == str.at(str.length() - cur)){
           cur++;
        // 두개가 다르면,?
        } else {
            //일단 palin은 아니니까
            ret += 1;
            break;
        }
    }
    // palin아니라면
    if (ret != 1) {
        // 앞에서 출발
        while(cur != center){
            if(str.at(cur+1) == str.at(str.length() - cur)){
                cur++;
            // 두개가 다르면,?
            } else {
                // 뒤에서 출발
                if(str.at(cur) == str.at(str.length() -1 -cur)){
                cur++;
                // 두개가 다르면,?
                } else {
                    // 끝 palin아님.
                    ret += 1;
                    break;
                }
            }
        }
    }
    return ret;
}

int main()
{
    string fName = "1.inp";
    // string oName = "1.out";

    ifstream openFile(fName.data());
    // ofstream writeFile(oName.data());
    if(openFile.is_open()){

        string line;
        getline(openFile, line);
        int n = atoi(line.c_str());
        for(int i = 0; i < n; i++)
        {
            getline(openFile, line);
            cout << chkpalin(line) << "\n";
        }
        openFile.close();
    }

    return 0;
}
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string chkpalin(string str){
    int ret = 1;
    // center를 chk
    int center = str.length() / 2;
    int last = str.length()-1;
    // curser
    int cur = 0;
    // cur를 증가시키는데, center에 도달할때까지
    // !짝수 홀수때 경우가 똑같을까? 
    while(cur != center){
        if(str.at(cur) == str.at(last - cur)){
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
            if(str.at(cur+1) == str.at(last - cur)){
                cur++;
            // 두개가 다르면,?
            } else {
                // 뒤에서 출발
                if(str.at(cur) == str.at(last -1 -cur)){
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
    return to_string(ret);
}

int main()
{
    ifstream ifs;
    ofstream ofs;

    ofs.open("palin.inp");
    ifs.open("palin.out");

    if(ofs.is_open()){
        string line;
        ofs << line;
        int n = atoi(line.c_str());
        for(int i = 0; i < n; i++)
        {
            ofs << line;
            ifs >> chkpalin(line) >> "\n";
        }
        ifs.close();
        ofs.close();
    }
    return 0;
}
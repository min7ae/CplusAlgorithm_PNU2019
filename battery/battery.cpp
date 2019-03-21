#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream ifs;
    ofstream ofs;

    ifs.open("battery.inp");
    ofs.open("battery.out");

    if(ifs.is_open()){
        
        ofs.close();
        ifs.close();
    }
    return 0;
}
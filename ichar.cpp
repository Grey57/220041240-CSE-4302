#include<fstream>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    char ch;
    ifstream infile("TEST.TXT");
    while(infile){
        infile.get(ch);
        cout<< ch;
    }
    cout<<endl;
    return 0;
}
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str = "Time is a great teacher, but unfortunately "
                 "it kills all its pupils. Berlioz";
    ofstream outfile("TEST.TXT");
    for(int j=0; j<str.size(); j++){
        outfile.put(str[j]);
    }
    cout<<"File writen\n";
    return 0;
}
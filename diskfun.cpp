#include <fstream> 
#include <iostream>
#include <string> 

using namespace std;

class Person 
{
protected:
    string name; 
    int age; 
public:
    void getData()
    {
        cout << "\n Enter name: "; 
        cin >> name;
        cout << " Enter age: "; 
        cin >> age;
    }

    void displayData()
    {
        cout << "\n Name: " << name;
        cout << "\n Age: " << age << endl;
    }
};

int main()
{
    char ch;
    Person pers;
    fstream file;
    file.open("GROUP.DAT", ios::app | ios::out | ios::in | ios::binary);

    do
    {
        cout<<"\n Enter person's data: ";
        pers.getData();

        file.write(reinterpret_cast<char*>(&pers), sizeof(pers));
        cout<<"Enter another person (y/n)? ";
        cin>>ch;
    } while (ch == 'y');
    file.seekg(0);

    file.read( reinterpret_cast<char*>(&pers), sizeof(pers));

    while(!file.eof()){
        cout<<"\n Person: ";
        pers.displayData();
        file.read( reinterpret_cast<char*>(&pers), sizeof(pers));
    }
    cout<<endl;
    
    return 0;
}

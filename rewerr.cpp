#include <fstream> // For file streams
#include <iostream>
#include <cstdlib> // For exit()
using namespace std;

const int MAX = 1000;
int buff[MAX];

int main() {
    for(int j = 0; j < MAX; j++) // Fill buffer with data
        buff[j] = j;

    ofstream os; // Create output stream

    // Open it
    os.open("a:edata.dat", ios::trunc | ios::binary);
    if(!os) {
        cerr << "Could not open output file\n";
        exit(1);
    }
    
    cout << "Writing...\n"; // Write buffer to it
    os.write(reinterpret_cast<char*>(buff), MAX * sizeof(int));
    if(!os) {
        cerr << "Could not write to file\n";
        exit(1);
    }
    os.close(); // Must close it

    for(int j = 0; j < MAX; j++) // Clear buffer
        buff[j] = 0;

    ifstream is; // Create input stream
    is.open("a:edata.dat", ios::binary);
    if(!is) {
        cerr << "Could not open input file\n";
        exit(1);
    }
    
    cout << "Reading...\n"; // Read file
    is.read(reinterpret_cast<char*>(buff), MAX * sizeof(int));
    if(!is) {
        cerr << "Could not read from file\n";
        exit(1);
    }
    
    for(int j = 0; j < MAX; j++) // Check data
        if(buff[j] != j) {
            cerr << "\nData is incorrect\n";
            exit(1);
        }
    
    cout << "Data is correct\n";
    return 0;
}

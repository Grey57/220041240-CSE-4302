#include <iostream>

using namespace std;

struct Curr {
    int pounds;
    int shillings;
    int pence;
};
// 12 pen = 1 shill
// 20 shill = 1 pound
Curr add(Curr a1, Curr a2) {
    Curr result;
    
    result.pence = a1.pence + a2.pence;
    result.shillings = a1.shillings + a2.shillings + result.pence / 12;  
    result.pounds = a1.pounds + a2.pounds + result.shillings / 20;       

    result.pence %= 12;     
    result.shillings %= 20;  

    return result;
}

int main() {
    char choice;

    do {
        char sep;
        Curr amount1;
        cout<<"Enter first amount: £";
        cin>>amount1.pounds>>sep>>amount1.shillings>>sep>>amount1.pence;
        cout<<"Enter Second amount: £";
        Curr amount2;
        cin>>amount2.pounds>>sep>>amount2.shillings>>sep>>amount2.pence;

        Curr total = add(amount1, amount2);

        cout << "Total is £" << total.pounds << "." << total.shillings << "." << total.pence << endl;

        cout << "Do you wish to continue (y/n)? ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

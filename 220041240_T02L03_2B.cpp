#include<iostream>
using namespace std;
class RationalNumber{
    private:
        int numerator;
        int denominator;
    public:
        void assign(int n,int d){
            if(d==0){
                cout<<"You can not assign 0 as denominator\n";
                return;
            }
            numerator = n;
            denominator = d;
        }
        float convert(){
            float res;
            res = (float)numerator/denominator;
            return res;
        }
        void invert(){
            if(numerator==0){
                cout<<"You can not assign 0 as denominator\n";
                return;
            }
            swap(numerator,denominator);
        }
        void print(){
            cout<<"The Rational Number is: "<<numerator<<"/"<<denominator<<'\n';
            return;
        }
};
int main(){
    RationalNumber f1;
    int funcID;
    cin>>funcID;
    while(funcID != -1){
        switch (funcID)
        {
        case 1:
            /* assign */
            cout<<"Enter the values of Numerator and Denominator: ";
            int numerator,denominator;
            cin>>numerator>>denominator;
            f1.assign(numerator, denominator);
            break;
        case 2:
            /* convert */
            cout<<"Decimal Value is: ";
            cout<<f1.convert()<<'\n';
            break;
        case 3:
            /* invert */
            f1.invert();
            break;
        case 4:
            /* print */
            f1.print();
            break;
        default:
            cout<<"Enter valid Function ID\n";
            break;
        }
        cin>>funcID;
    }
    return 0;
}
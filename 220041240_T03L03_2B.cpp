#include<iostream>
#include<string>
using namespace std;
class Medicine{
    private:
        string name;
        string genricName;
        double price=0;
        double discount=5;
    public:
        void assignName(string n, string gn){
            name = n;
            genricName = gn;
            return;
        }
        void assignPrice(double p){
            if(price<0){
                cout<<"Price cannot be negative\n";
                return;
            }
            price = p;
            return;
        }
        void setDiscountPercent(double percent){
            if(percent<0){
                cout<<"Invalid input\n";
                return;
            }
            discount = percent;
            return;
        }
        double getSellingPrice(int nos){
            double res = price - price*(discount/100);
            res = nos*res;
            return res;
        }
        void display(){
            cout<<"MRP. of "<<name<<"("<<genricName<<")"<<"is BDT "<<price<<"."<<" Current discount: "<<discount<<"%"<<" Selling price BDT "<<getSellingPrice(1);
            return;
        }
};
int main(){
    Medicine m1;
    string name, genricName;
    cin>>name>>genricName;
    m1.assignName(name,genricName);
    double price;
    cin>>price;
    m1.assignPrice(price);
    double percent;
    cin>>percent;
    m1.setDiscountPercent(percent);
    int nos;
    cin>>nos;
    m1.getSellingPrice(nos);
    m1.display();
    return 0;
}
#include<iostream>
using namespace std;
class Counter{
    private:
        int count;
    public:
        void setIncrementStep(int step){
            count = step;
            return;
        }
        int getCount(){
            return count;
        }
        void resetCount(){
            count = 0;
        }
        void increment(int val){
            count += val;
        }
};
int main(){
    Counter c1;
    int step, val;
    int funcID;
    cout<<"set count: 1\n";
    cout<<"Get Count: 2\n";
    cout<<"increment count: 3\n";
    cout<<"Enter Function ID: ";
    cin>>funcID;
    switch (funcID)
    {
    case 1:
        cin>>step;
        c1.setIncrementStep(step);
        break;
    case 2:
        cout<<"Count: "<<c1.getCount()<<endl;
        break;
    case 3:
        cin>>val;
        c1.setIncrementStep(val);
        break;
    
    default:
        break;
    }
}
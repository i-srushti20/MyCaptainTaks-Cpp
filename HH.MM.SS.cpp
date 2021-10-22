#include<iostream>
using namespace std;

class second_calculator
{
    int hr,min,sec;
public:
    void input(void);
    int sec_cal();
};

void second_calculator :: input(void)
{
    cout<<"Enter time :\nHours : ";
    cin>>hr;
    cout<<"Minutes :";
    cin>>min;
    cout<<"Seconds :";
    cin>>sec;
}

int second_calculator :: sec_cal(){
    int s=(hr*60*60)+(min*60)+(sec);
    return s;
}

int main(){
second_calculator alfa;
alfa.input();
cout<<"seconds: "<<alfa.sec_cal();

return 0;
}

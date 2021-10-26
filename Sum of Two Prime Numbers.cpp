#include<iostream>
#include<math.h>
using namespace std;

int prime(int n){
    for (int  i = 2; i < sqrt(n); i++)
    {
        if (n%i==0)
        {
            return 0;
        }
    }
    return n;
}

int main(){
int n;
cout<<"Enter a positive integer:";
cin>>n;

for (int  i = 2; i < n; i++)
{
    for (int  j = i; j < n; j++)
    {
        if (prime(i)+prime(j)==n)
        {
            cout<<n<<" = "<<i<<" + "<<j<<endl;
        }
    }   
}

return 0;
}

#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cout<<"please enter Number input elements: ";
    cin>>n;
int arr[n];
cout<<"Enter elements : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
cout<<"You entered :";
    for (int i = 0; i < n; i++)
    {
        cout<<" "<<arr[i];
    }
return 0;
}

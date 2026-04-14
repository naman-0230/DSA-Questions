#include<iostream>
using namespace std;

int main(){
 int n;
cout<<"enter number of elements";
cin>>n;
int arr[n];
cout<<"enter the elements";
for(int i=0; i<n; i++){
cin>>arr[i];
}

int a =arr[0];
for(int i=0;i<n-1;i++){
    arr[i]=arr[i+1];
  }
arr[n-1]=a;  

for(int i=0;i<n;i++){
    cout<<arr[i];
}

return 0;
}
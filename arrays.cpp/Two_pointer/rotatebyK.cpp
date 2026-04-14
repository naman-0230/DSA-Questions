#include<iostream>
using namespace std;
int main(){
 int n;
cout<<"enter number of elements";
cin>>n;
int arr[n];
cout<<"enter the elements;";
for(int i=0; i<n; i++){
cin>>arr[i];
}
int k;
cout<<"enter k:";
cin>>k;
int a[n];
for(int j=0; j<n; j++){
    a[j]=arr[(j+k)%n];
}
for(int i=0; i<n; i++){
    cout<<a[i]<<" ";
}
return 0;
}
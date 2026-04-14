#include<iostream>
#include<algorithm>
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

sort(arr,arr+n);
for(int i=0;i<n-1;i++){
    if((arr[i]==arr[i+1])&&((i==n-2)||arr[i]!=arr[i+2])){      // short circuit important
        cout<<arr[i]<<" ";
    }
}

return 0;
}
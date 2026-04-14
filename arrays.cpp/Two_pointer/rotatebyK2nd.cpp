#include<iostream>
using namespace std;
void reverseArray(int arr[], int size){
    int a=0, b= size-1;
        while(a<b)
        {
            swap(arr[a],arr[b]);
            a++;
            b--;
        }
    }

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
cout<<"enter k";
cin>>k;
reverseArray(arr,n);
reverseArray(arr,k);
reverseArray(arr+k,n-k);
for(int i=0; i<n; i++){
cout<<arr[i]<<" ";
}
return 0;
}
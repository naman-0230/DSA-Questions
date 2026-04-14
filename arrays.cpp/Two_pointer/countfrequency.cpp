#include<iostream>
#include<climits>
using namespace std;
int Max(int arr[], int n){
    int max= INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]>max){
            max= arr[i];
        }
    }
    return max;
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
int x= Max(arr,n);

int farr[x+1]={0};

for(int i=0;i<n;i++){
    farr[arr[i]]++;
}
for(int i=0; i<x+1; i++){
    if(farr[i]!=0){
        cout<<i<<" has appeared "<<farr[i]<<" times";
        cout<<endl;
         }
}

int max= 0; 
    for(int i=0; i<x+1; i++){
        if(farr[i]>max){
            max= farr[i];
        
        }
    }
    cout<<endl;
    for(int i = 0; i < x+1; i++) {
        if(max==farr[i]) {
            cout << i << " ";}
        }
        cout<<" has appeared the most";

return 0;
}
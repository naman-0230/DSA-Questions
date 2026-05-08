#include<iostream>
using namespace std;
void reverseArray(int arr[], int n){
    int i=0,j=n-1;
    while(i<=j){
    swap(arr[i],arr[j]);  
    i++;
    j--;   
    }

}

int main(){
  int n;
    cout<<"enter number of elements:";
    cin>>n;

 int arr[n];
   cout<<"enter the elements";
  for(int i=0; i<n; i++){
 cin>>arr[i];
  }
  reverseArray(arr,n);
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
return 0;
}
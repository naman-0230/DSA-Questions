#include<iostream>
using namespace std;

int lowerBound(int arr[], int n, int target){
    int i=0,j=n-1;
    int index= -1; 
       
    while(i<=j){
     int mid= i+ (j-i)/2;
    //  if(arr[mid]==target){
    //     index= mid;            
    //     j= mid-1;            // for First Occurrence
    //    // i= mid+1;              // for Last Occurrence
     if(arr[mid]<target){
         i= mid+1;
             
     }
     else{
        j= mid-1;
     }
    }
   
 return i;
  
}

int main(){
 int n;
cout<<"enter number of elements:";
cin>>n;
int arr[n];
cout<<"enter the elements:";
for(int i=0; i<n; i++){
cin>>arr[i];
}
cout<< "enter the target";
int target;
cin>>target;

if(target>arr[n-1]){
    cout<<"put correct target value";
}
else{
int lb = lowerBound(arr,n,target);

cout<<lb<<" index place is the lower bound";
}

return 0;
}
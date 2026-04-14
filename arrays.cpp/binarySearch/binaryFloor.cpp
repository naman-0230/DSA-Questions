#include<iostream>
using namespace std;

int floorArray(int arr[], int n, int target){
    int i=0,j=n-1; 
       
    while(i<=j){
     int mid= i+ (j-i)/2;
     if(arr[mid]==target){          
       return arr[mid];}
     else if(arr[mid]<target){
         i= mid+1;
             
     }
     else{
        j= mid-1;
     }
    }
   
 return arr[i-1];
  
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

if(target<arr[0]){
    cout<<"put correct target value";
}
else{
int lb = floorArray(arr,n,target);

cout<<lb<<" is the floor";
}

return 0;
}
#include<iostream>
using namespace std;

int insertNo(int arr[], int n, int target){
    int i=0,j=n-1; 
       
    while(i<=j){
     int mid= i+ (j-i)/2;
     if(arr[mid]==target){          
       return mid;}

     else if(arr[mid]<target){
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


int lb = insertNo(arr,n,target);

cout<<lb<<" is the index place where target should be places in given array";


return 0;
}
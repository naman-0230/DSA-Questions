#include<iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int target){
    int i=0,j=n-1;
    int index= -1;  
    while(i<=j){
     int mid= i+ (j-i)/2;
     if(arr[mid]==target){
        index= mid;            
        j= mid-1;            // for First Occurrence
       // i= mid+1;              // for Last Occurrence
     }
     else if(arr[mid]<target){
        i= mid+1;
     }
     else{
        j= mid-1;
     }
    }
 return index;
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

int answerIndex= firstOccurrence(arr,n,target);
if(answerIndex!=-1)
cout<<answerIndex;
else
cout<<"not found";

return 0;
}
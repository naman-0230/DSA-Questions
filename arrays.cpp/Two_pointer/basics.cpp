#include<iostream>
#include<climits>
using namespace std;
void reverseArray(int arr[], int size){
    int a=0, b= size-1;
        while(a<b)
        {
            swap(arr[a],arr[b]);
        }
    }

void printArray(int a[], int n){
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    
};
int sumArray(int arr[], int n){
    int sum=0;
    for(int i=0; i<n; i++){
      sum+= arr[i];
    }
    return sum; 
}

int Max(int arr[], int n){
    int max= INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]>max){
            max= arr[i];
        }
    }
    return max;
 }


int Min(int arr[], int n){
    int min= INT_MAX;
    for(int i=0; i<n; i++){
        if(arr[i]<min){
        min= arr[i];
        }
    
    }
    return min; 
}

int countOdd(int arr[], int n){
    int count=0;
    for(int i=0; i<n; i++){
        if(arr[i]%2!=0){
        count++;
        }
    
    }
    return count; 
}
void linearSearch1(int arr[], int n, int target){

    bool flag = false;
    for(int i=0; i<n; i++){
        if(arr[i]== target){
        cout<< "found";
        flag= true;
        break;
    }
}
       if(!flag){
    cout<<"not found";
        }
    }

int linearSearch(int arr[], int n, int target){

   
    for(int i=0; i<n; i++){
        if(arr[i]== target){
            return i+1;
        }
    }
    return -1;
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
  int target;
  cout<< "enter the target value";
  cin>> target;
 cout<< sumArray(arr, n)<<" ";
 cout<< Max(arr, n)<<" ";
 
 cout<< Min(arr, n)<<" ";
 cout<< countOdd(arr, n)<<" ";
 int result;
 result =linearSearch(arr,n,target);
 if(result!=-1){
    cout<<" element is found in " <<linearSearch(arr,n,target)<<" position";
 }
 else if(result=-1){
    cout<<"element is not found";}

return 0;
}

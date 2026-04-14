#include<iostream>
#include<algorithm>
using namespace std;

void sortFlag(int arr[], int n){
    int i = 0, current = 0, j= n-1;
    
    while(current <= j){
        if(arr[current]==0){
          swap(arr[current],arr[i]);
          i++;
          current++;
        }
        else if(arr[current]==2){
            swap(arr[current],arr[j]);
            j--;                                  // not this time current++
        }
        else{
            current++;
        }
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
sortFlag(arr,n);

for(int i=0; i<n; i++){
    cout<<arr[i];
}
return 0;
}
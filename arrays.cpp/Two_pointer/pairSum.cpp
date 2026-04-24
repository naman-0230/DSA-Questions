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

cout<<"target value";
int target;
cin>>target;

sort(arr,arr+n);

int i=0, j=n-1;
bool flag=true;
while(i<j){
    int sum= arr[i]+arr[j];
    if(sum==target){
        cout<<arr[i]<<" "<<arr[j]<<" make the fized sum"<<endl;
        i++;
        j--;
        flag=false;
         while(i < j && arr[i] == arr[i-1]) i++;        //for duplicates
            while(i < j && arr[j] == arr[j+1]) j--;
    }
    else if(sum<target){
        i++;
    }
    else
       j--;

}
 if(flag){
    cout<<"sum pairs not found";
 }
return 0;
}
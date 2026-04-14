#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
 int n;
cout<<"enter number of elements:";
cin>>n;
vector<int>arr(n);
cout<<"enter the elements;";
for(int i=0; i<n; i++){
cin>>arr[i];
}

int i=0, j=n-1, watermax=0, x;
while(i<j){
  x=min(arr[i],arr[j])*(j-i);
  watermax= max(x,watermax);
  if(arr[i]<arr[j]){ i++;}
  else{ j--;}
}

cout<<watermax;

return 0;
}
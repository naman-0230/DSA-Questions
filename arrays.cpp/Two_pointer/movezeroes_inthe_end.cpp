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
int zeroesfound =0;
for(int i=0; i<n-zeroesfound; i++){          
    if(arr[i]==0){
        for(int j=i;j<n-1;j++){         //left shift
            arr[j]=arr[j+1];
        }
      arr[n - 1 - zeroesfound]=0;
      zeroesfound++;  //imp again
      i--;    //important concept
    }
}

for(int i=0; i<n;i++){
    cout<<arr[i];
}

return 0;
}


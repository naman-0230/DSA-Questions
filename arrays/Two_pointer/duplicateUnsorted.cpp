#include <iostream>
using namespace std;
int main()
{   
    int n, k, i, j;
    cout<< "enter no. of elements"<<endl;
    cin >> n;
    
    int arr[n];
    cout<< "enter array numbers";
    for(int i=0; i<n ;i++)
    cin>> arr[i];
    for(int i=0; i<n-1;++i){
      for(int j=i+1; j<n;++j)
    {
      if(arr[i]==arr[j])
      {
        for(k=j; k<n-1; ++k){
        arr[k]=arr[k+1];}
        n--;
        j--;
      }
    }
    
    }
    for(int i =0; i<n; i++)
    cout<<arr[i];
return 0;}
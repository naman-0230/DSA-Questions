#include<iostream>
#include<vector>
using namespace std;

long long power(int base, int n, int k){
    long long result = 1;
    for(int i=0; i<n; i++){
      result*= base;
      if(result > k){
        return -1;
      }
    }
    return result;
}

 int findnth_root(int k, int n){
 
    int i = 1, j= k;
    while(i<=j){
        int mid = i+ (j-i)/2;
        long long pow = power(mid,n,k);

        if(pow== -1){
            j= mid-1;
        }
        else if(pow < k){
            i= mid+1;
        }
        else{
          return mid;  
        }
    }
    return -1;
 }
int main(){
    int k;
    cin>>k;
    int n;
    cin>> n;
     
cout<< findnth_root(k,n);


    return 0;
}
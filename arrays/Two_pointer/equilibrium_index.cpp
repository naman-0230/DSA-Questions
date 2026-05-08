#include<iostream>
using namespace std;

int sumArray(int arr[], int n){
    int sum=0;
    for(int i=0; i<n; i++){
      sum+= arr[i];
    }
    return sum; 
}
int main(){

    int arr[8]= {0, -3, 5, -4, -2, 3, 1, 0};
    int n;
    n= sizeof(arr)/sizeof(arr[0]);

   int x= sumArray(arr,n);

   int l_sum=0, r_sum=0;
   cout<<"equilibrium indexes:"<<endl;
   for(int i=0;i<n;i++){
    if(i==0){
        l_sum=0;
    }
     else
     {l_sum= l_sum+ arr[i-1];}

     r_sum = (x- l_sum- arr[i]);
     if(r_sum==l_sum){
        cout<<i<<" ";
     }
   }
  
 
return 0;
}


   // int i=0, j= n-1;
    // int sum1=0, sum2=0;
    // int count=0;
    // while(i<j){
    //     if(sum1<sum2){
    //         sum1+=arr[i];
    //         i++;
    //         count++;
    //     }
    //     else if(sum2<sum1){                    //// TWO POINTER FAILED FOR THIS/////
    //         sum2+=arr[j];
    //         j--;
    //     }
    //     else{
    //        sum1+=arr[i];
    //        sum2+=arr[j];
    //        i++;
    //        j--;
    //        count++;
    //     }
    
    // }
    // if(sum1!=sum2){
    //     cout<<"Not found";
    // }
    // else
    // {cout<<count;}
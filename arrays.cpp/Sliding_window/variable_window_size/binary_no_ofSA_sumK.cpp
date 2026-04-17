#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

int sumK(vector<int> &v ,int k){

int sum= 0, count = 0;
int j=0;

for(int i=0; i< v.size(); i++){                 ///sliding window ONLY FOR POSITIVE NO.
   sum+= v[i];
   
   while(sum>k){
    sum-= v[j];
    j++;
   }

    count += i-j+1;            // this count is for SA whose sum <= k
   }                          // for sum == k .. we cant put count directly as break test case e.g is 10101
           // so we calculate sum <=k and sum <=k-1    
         // and subtracting both will give count where sum == k

return count;
}

int main(){
 vector<int> v ={1,0,1,0,1};//{1,0,1,1,0,1,0,1,0,0};
int k = 2;

int ans= sumK(v,k) - sumK(v,k-1);
cout<< ans;
return 0;
}
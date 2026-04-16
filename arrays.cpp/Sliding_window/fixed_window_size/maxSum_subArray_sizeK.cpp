#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
 vector<int> v ={2,3,5,1,2,4};
int k = 3;

int sum= 0;
for(int i=0; i<k; i++){
    sum+= v[i];
   }

int maxsum = sum;

for(int i=k; i< v.size() ;i++){         //basic sliding window
   sum += v[i];
   sum -= v[i-k];
   maxsum= max(maxsum, sum);
}

cout<< maxsum;

return 0;
}
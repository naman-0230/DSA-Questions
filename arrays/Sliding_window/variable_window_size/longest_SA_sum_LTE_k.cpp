#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

int main(){
 vector<int> v ={1,3,2,1,2,4,2,3,4,2};
int k = 6;
int sum= 0; 
int length,   max_length= 0;
int j=0;

for(int i=0; i< v.size(); i++){                 ///sliding window ONLY FOR POSITIVE NO.
    sum += v[i];
    while(sum > k){
     sum-= v[j];
     j++;
    }
    length = i-j+1;
    max_length = max(length, max_length);
 }

cout<<max_length;

return 0;
}
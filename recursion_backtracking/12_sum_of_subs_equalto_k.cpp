#include<iostream>
#include<vector>
using namespace std;

void subs(vector<int> &v, int idx, int &curr_sum, int k, int &count){

    if(idx == v.size()){
        
        if(curr_sum == k) count++;
        return;
    }

    curr_sum += v[idx];
    subs(v, idx+1, curr_sum, k, count);

    curr_sum -= v[idx]; 
    
    subs(v, idx+1, curr_sum, k, count);
    
}
/// try int curr_sum to pass by value as well.. for fun

int main(){

    vector<int> v={1,2,3,3,1,1};
    int k = 3;

    int curr_sum = 0; int count = 0;
    subs(v,0,curr_sum,k, count);

    cout<< count;
return 0;
}
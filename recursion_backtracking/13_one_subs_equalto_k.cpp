// Print One Subsequence with Sum = K ⭐
// Problem : Given:
// v = {1,2,1}
// k = 2

// Print only one subsequence whose sum is 2.

#include<iostream>
#include<vector>
using namespace std;

bool subs(vector<int> &v, int idx, int &curr_sum, int k, vector<int> &curr){

    if(idx == v.size()){
        
        if(curr_sum == k){
            for(int x:curr){
                cout<<x<<" ";
            }
            return true;
        }
        return false;
    }
    

    curr_sum += v[idx];
    curr.push_back(v[idx]);
    if(subs(v, idx+1, curr_sum, k, curr)) return true;

    curr_sum -= v[idx]; 
    curr.pop_back();

    if(subs(v, idx+1, curr_sum, k, curr)) return true;

    return false;
}

int main(){

    vector<int> v={1,2,3,3,1,1};
    int k = 3;

    int curr_sum = 0;
    vector<int> curr;
    subs(v,0,curr_sum,k,curr);

return 0;
}
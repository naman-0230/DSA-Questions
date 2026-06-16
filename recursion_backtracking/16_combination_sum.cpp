#include<iostream>
#include<vector>
using namespace std;

void combo(vector<int> &v, int idx, int k, vector<int> &curr, int &curr_sum, vector<vector<int>> &ans){
   
    if(idx == v.size()){
        return;
    }
    if(curr_sum > k){
        return;
    }
    if(curr_sum == k){
        ans.push_back(curr);
        return;
    }


    curr.push_back(v[idx]);
    curr_sum += v[idx];
    combo(v,idx,k,curr,curr_sum,ans);

    curr.pop_back();
    curr_sum -= v[idx];
    combo(v,idx+1,k,curr,curr_sum,ans);

}

int main(){
    vector<int> v = {2,3,4};
    int k = 7;

    vector<int> curr;
    vector<vector<int>> ans;
    int curr_sum = 0;

    combo(v,0,k,curr,curr_sum,ans);

    for(auto x: ans){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
return 0;
}
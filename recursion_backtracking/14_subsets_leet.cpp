#include<iostream>
#include<vector>
using namespace std;

void subs(vector<int> &v, int idx, vector<int> &curr, vector<vector<int>> &ans){

    if(idx == v.size()){
        ans.push_back(curr);
        return;
    }

    curr.push_back(v[idx]);
    subs(v, idx+1, curr, ans);

    curr.pop_back();

    subs(v, idx+1, curr, ans);

    return;
}

int main(){

    vector<int> v={1,2,3};
    vector<int> curr = {};
    vector<vector<int>> ans;

    subs(v,0,curr,ans);
   
return 0;
}
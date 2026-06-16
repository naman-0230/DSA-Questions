#include<iostream>
#include<vector>
using namespace std;

void perm(vector<int> &v, int start, vector<int> &curr, vector<bool> &used, vector<vector<int>> &ans){

    if(curr.size() == v.size()){
        ans.push_back(curr);
        // fill(used.begin(), used.end(),false);
        return;
    }

    for(int i= start; i < v.size(); i++){
        if(used[i]) continue;

        curr.push_back(v[i]);
        used[i] = true;
        perm(v,0,curr,used,ans);

        curr.pop_back();
        used[i] = false;
    }
}

int main(){
    vector<int> v = {1,2,3};
    vector<vector<int>> ans;
    vector<int> curr;
    vector<bool> used(v.size(), false);
    
    perm(v,0,curr,used,ans);

    for(auto x: ans){
        for(int y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

return 0;
}
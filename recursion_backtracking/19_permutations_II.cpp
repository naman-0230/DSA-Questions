#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void perm(vector<int> &v, int start, vector<int> &curr, vector<bool> &used, vector<vector<int>> &ans){

    if(curr.size() == v.size()){
        ans.push_back(curr);

        return;
    }

    for(int i= start; i < v.size(); i++){

        if(used[i]) continue;

        if(i> start && v[i]==v[i-1] && !used[i-1]) continue; //////importanttt one here
        
        curr.push_back(v[i]);
        used[i] = true;
        perm(v,0,curr,used,ans);

        curr.pop_back();
        used[i] = false;
    }
}

int main(){
    vector<int> v = {1,2,2};
    vector<vector<int>> ans;
    vector<int> curr;
    vector<bool> used(v.size(), false);

    sort(v.begin(), v.end());
    perm(v,0,curr,used,ans);

    for(auto x: ans){
        for(int y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

return 0;
}
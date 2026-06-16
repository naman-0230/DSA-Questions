#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void combo(vector<int> &v, int start, int k, vector<int> &curr, int &curr_sum, vector<vector<int>> &ans){

    if(curr_sum == k){
        ans.push_back(curr);
        return;
    }
    if(curr_sum > k){
        return;
    }

    for(int i = start; i < v.size(); i++){

        if(i>start && v[i] == v[i-1]) continue;

        if(curr_sum + v[i] > k)  break;                    ///////important optimzationnn
  

        curr.push_back(v[i]);
        curr_sum += v[i];
        combo(v,i+1,k,curr,curr_sum, ans);

        curr.pop_back();
        curr_sum -= v[i];
    }

}

int main(){
    vector<int> v = {2,3,3,1,3};
    int k = 5;

    vector<int> curr;
    vector<vector<int>> ans;
    int curr_sum = 0;

    sort(v.begin(), v.end());

    combo(v,0,k,curr,curr_sum,ans);

    for(auto x: ans){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> ans;

void subs(vector<int> &nums, int start, vector<int> &curr){

    ans.push_back(curr);

    for (int i = start; i < nums.size(); i++){        //new concept of for with recursion 
        if(i>start && nums[i] == nums[i-1]) continue;

        curr.push_back(nums[i]);

        subs(nums, i + 1, curr);

        curr.pop_back();
    }
}
int main(){

    vector<int> v = {4,4,4,1,4};
    vector<int> curr = {};
    
    sort(v.begin(), v.end());            ///important to do this 
    subs(v, 0, curr);

    for(auto x: ans){
        cout<<"{";
        for(int y:x){
            cout<<y<<" ";
        }
        cout<<"}"<<endl;
    }

    return 0;
}
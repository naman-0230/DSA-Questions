#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>> ans;

void combo(int k, int n, int start, vector<int> &curr, int &curr_sum){
    if(curr_sum > n) return;

    if(curr_sum == n && curr.size() == k){
        ans.push_back(curr);
        return;
    }

    if(curr.size() > k) return;

    for(int i= start; i<=9; i++){  //grasp the start logic cause its the only bug before
    //not using used and just using start one cause if we use used and only skip the previous number 
    //we will get 1 2 3, 2 1 3, 3 1 2 kinda answer but we want unique combination

        if(curr_sum + i > n) break;

        curr.push_back(i);
        curr_sum += i;
        combo(k, n, i+1, curr, curr_sum);

        curr.pop_back();
        curr_sum -= i;
    }
}

int main(){
    int k = 3;
    int n = 7;
    vector<int> curr;
    int curr_sum = 0;

    combo(k,n,1,curr,curr_sum);

    for(auto x: ans){
        for(int y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

return 0;
}
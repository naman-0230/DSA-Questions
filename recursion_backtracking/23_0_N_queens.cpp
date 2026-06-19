#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

vector<vector<int>> ans;

bool isPossible(int i, vector<int> &curr){
    int i_idx = curr.size() + 1;

    for(int x=0; x<curr.size(); x++){

        if((x+1 + (curr[x]) == i_idx + i) || (x+1 - (curr[x]) == i_idx - i) || 
            (curr[x]) == i) return false;
    }
    return true;
}

void n_queens(int n, int idx, vector<int> &curr){

    if(curr.size()==n){
        ans.push_back(curr);
        return;
    }

    for(int i = 1; i <= n; i++){

        if(!isPossible(i,curr)) continue;

        curr.push_back(i);
        n_queens(n, idx+1, curr);

        curr.pop_back();
    }

}

int main(){

    int n = 4;
    vector<int> curr;

    n_queens(n,1,curr);

    for(auto x: ans){
        for(int y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

return 0;
}
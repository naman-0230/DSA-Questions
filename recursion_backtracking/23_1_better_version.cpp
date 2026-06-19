#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>   //board version
using namespace std;

vector<vector<string>> ans;

bool isPossible(int idx, int col, vector<string> &curr){

    for(int i=0; i<idx; i++){
        if(curr[i][col] == 'Q') return false;
    }

    int r = idx;
    int c = col;
    while(r>=0 && c>=0){
        if(curr[r][c] == 'Q') return false;
        r--;
        c--;
    }

    r = idx;
    c = col;
    while(r>=0 && c>=0){
        if(curr[r][c] == 'Q') return false;
        r--;
        c++;
    }

    return true;
}

void n_queens(int n, int idx, vector<string> &curr){

    if(idx >= n){
        ans.push_back(curr);
        return;
    }

    for(int col = 0; col < n; col++){

        if(!isPossible(idx,col,curr)) continue;

        curr[idx][col] = 'Q'; 
        n_queens(n, idx+1, curr);

        curr[idx][col] = '.';
    }

}

int main(){

    int n = 4;
    vector<string> curr(n, string(n , '.'));
    n_queens(n,0,curr);

    for(auto x: ans){
        for(auto y: x){
           cout<<y<<endl;
        }
        cout<<endl;
    }

return 0;
}
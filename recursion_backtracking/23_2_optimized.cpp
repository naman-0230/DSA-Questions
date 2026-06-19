#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>   //board version
using namespace std;

vector<vector<string>> ans;

bool isPossible(int n, int idx, int col, vector<bool> &col_used,
                vector<bool> &left_diagonal_used, vector<bool> &right_diagonal_used){

    if(col_used[col] || left_diagonal_used[idx+col] || right_diagonal_used[idx-col+ n-1]) return false;  
    
    return true;
}

void n_queens(int n, int idx, vector<string> &curr, vector<bool> &col_used,
                vector<bool> &left_diagonal_used, vector<bool> &right_diagonal_used){

    if(idx >= n){
        ans.push_back(curr);
        return;
    }

    for(int col = 0; col < n; col++){

        if(!isPossible(n,idx,col , col_used, left_diagonal_used, right_diagonal_used)) continue;

        curr[idx][col] = 'Q'; 
        col_used[col] = true;
        left_diagonal_used[idx+col] = true;
        right_diagonal_used[idx-col + n-1] = true;
        n_queens(n, idx+1, curr, col_used, left_diagonal_used, right_diagonal_used);

        curr[idx][col] = '.';
        col_used[col] = false;
        left_diagonal_used[idx+col] = false;
        right_diagonal_used[idx-col +n-1] = false;
    }

}

int main(){

    int n = 4;
    vector<string> curr(n, string(n , '.'));
    vector<bool> col_used(n, false);
    vector<bool> right_diagonal_used(2*n-1, false);
    vector<bool> left_diagonal_used(2*n-1, false);


    n_queens(n,0,curr, col_used, left_diagonal_used, right_diagonal_used);

    for(auto x: ans){
        for(auto y: x){
           cout<<y<<endl;
        }
        cout<<endl;
    }

return 0;
}
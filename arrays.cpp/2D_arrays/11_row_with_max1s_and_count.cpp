#include<iostream>
#include<vector>
using namespace std;

vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    int i = 0, j = m - 1;                 /////staircase method////
    int row = -1, count = 0;

    while(i < n && j >= 0){
        if(mat[i][j] == 1){
            row = i;
            count = m - j;   // number of 1s in this row
            j--;             // move left
        }
        else{
            i++;             // move down
        }
    }

    // if no 1 found at all
    if(row == -1) return {0, 0};

    return {row, count};
}

int main(){
    vector<vector<int>> mat = {
        {0,0,1,1},
        {0,1,1,1},
        {0,0,0,1}
    };

    vector<int> ans = rowAndMaximumOnes(mat);
    cout << ans[0] << " " << ans[1];
}
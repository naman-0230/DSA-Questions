// Diagonal Traversal (Top-left → Bottom-right)
// Print the matrix diagonal by diagonal, starting from the top row, moving in this direction:

// ↙ (down-left)

// That means:

// i++, j--
// 🧪 Matrix
// 1 2 3              
// 4 5 6               
// 7 8 9
// 🧠 How diagonals are formed

// We start from the top row, each column:

// 🔹 Start at (0,0)
// 1
// 🔹 Start at (0,1)
// 2 → 4
// 🔹 Start at (0,2)
// 3 → 5 → 7

// Then we move to the last column, starting from row 1:

// 🔹 Start at (1,2)
// 6 → 8
// 🔹 Start at (2,2)
// 9
// ✅ Final Output (line by line)
// 1
// 2 4
// 3 5 7
// 6 8
// 9

#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>> mat = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
};

vector<int>ans;

for(int col=0; col< mat[0].size(); col++){
    int j= col;
    int i=0;
    while(i<mat.size() && j>=0){
        ans.push_back(mat[i][j]);
        i++;
        j--;
    }
}

for(int row=1; row< mat.size(); row++){
    int i = row;
    int j= mat[0].size()-1;

    while(i<mat.size()){
        ans.push_back(mat[i][j]);
        i++;
        j--;
    }
}

for(int x :ans){
    cout<< x<< " ";
}   

return 0;
}
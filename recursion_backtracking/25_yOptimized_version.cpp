#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool sudoku(int idx, vector<vector<char>> &board, vector<vector<bool>> &row_used,
    vector<vector<bool>> &col_used, vector<vector<bool>> &box_used){

    if(idx == 81) return true;

    int row = idx/9;
    int col = idx%9;

    if(board[row][col] != '.'){
        // if(sudoku(idx+1, board)) return true;
        // return false;
        return sudoku(idx+1, board, row_used, col_used, box_used);
    }

    for(int i = 1; i <= 9; i++){

        int box = (row/3)*3 + col/3;     //cordinates of box imppppppppppp

        if(row_used[row][i] == true || col_used[col][i] == true ||
            box_used[box][i] == true) continue;

        board[row][col] = i + '0';

        row_used[row][i] = true;
        col_used[col][i] = true;
        box_used[box][i] = true;

        if(sudoku(idx+1, board, row_used, col_used, box_used)) return true;

        board[row][col] = '.';
        row_used[row][i] = false;
        col_used[col][i] = false;
        box_used[box][i] = false;
    }

    return false;
}

int main(){
vector<vector<char>> board = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
};

vector<vector<bool>> col_used(9, vector<bool>(10,false));
vector<vector<bool>> row_used(9, vector<bool>(10,false));
vector<vector<bool>> box_used(9, vector<bool>(10,false));

for (int row = 0; row < 9; row++) {          //imp steppp
    for (int col = 0; col < 9; col++) {
        if (board[row][col] != '.') {
            int num = board[row][col] - '0';
            int box = (row / 3) * 3 + (col / 3);

            row_used[row][num] = true;
            col_used[col][num] = true;
            box_used[box][num] = true;
        }
    }
}


sudoku(0, board, row_used, col_used, box_used);

for(auto x:board){
    for(char c: x){
        cout<<c<<" ";
    }
    cout<<endl;
}
return 0;
}
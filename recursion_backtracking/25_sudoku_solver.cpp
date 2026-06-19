#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isPossible(int num, int row, int col, vector<vector<char>> &board){

    for(int i=0; i<9; i++){
        if(board[i][col] == num+'0') return false;
    }
    for(int i=0; i<9; i++){
        if(board[row][i] == num+'0') return false;
    }

    //3 X 3 box
    int r = row/3;
    int c = col/3; 
    int top_left_row = r*3;
    int top_left_col = c*3;

    for(int i = top_left_row; i < top_left_row + 3; i++){
        for(int j = top_left_col; j < top_left_col + 3; j++){
            if(board[i][j] == num+'0') return false;
        }
    }
   

    return true;
}

bool sudoku(int idx, vector<vector<char>> &board){

    if(idx == 81) return true;

    int row = idx/9;
    int col = idx%9;

    if(board[row][col] != '.'){
        // if(sudoku(idx+1, board)) return true;
        // return false;
        return sudoku(idx+1, board);
    }

    for(int i = 1; i <= 9; i++){

        if(!isPossible(i, row, col, board)) continue;

        board[row][col] = i + '0';
        if(sudoku(idx+1, board)) return true;

        board[row][col] = '.';
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

sudoku(0, board);

for(auto x:board){
    for(char c: x){
        cout<<c<<" ";
    }
    cout<<endl;
}
return 0;
}
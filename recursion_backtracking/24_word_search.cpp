#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> dr = {1,0,0,-1};
vector<int> dc = {0,-1,1,0};
string dir = "DLRU";

bool word_search(int row, int col, int row_size, int col_size, int idx, 
    vector<vector<bool>> &visited, vector<vector<char>> &board, string &word){

    if(idx == word.size()) return true;

    for(int i=0; i<4; i++){
        int nr = row + dr[i];
        int nc = col + dc[i];

        if(nr < 0 || nr >= row_size || nc < 0 || nc >= col_size) continue;
        if(board[nr][nc] != word[idx]) continue;
        if(visited[nr][nc]) continue;

       
        visited[nr][nc] = true;
        if(word_search(nr, nc, row_size, col_size, idx+1, visited, board, word)) return true;
      
        visited[nr][nc] = false;
    }

    return false;
}

int main(){
    vector<vector<char>> board= {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}};
    
    int row_size = board.size();
    int col_size = board[0].size();

    string word = "BCCED";

    vector<vector<bool>> visited(row_size,vector<bool>(col_size,false));
    
    bool flag = false;

    for(int i = 0; i < row_size; i++){
        for(int j = 0; j < col_size; j++){
            if(board[i][j] == word[0]){
                visited[i][j] = true;
                if(word_search(i, j, row_size, col_size, 1, visited, board, word)){
                    flag = true;
                    break;
                }
                visited[i][j] = false;   
            }
        }
        if(flag) break;
    }

    cout<<flag;


return 0;
}
#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> ans;
vector<int> dr = {1,0,0,-1};
vector<int> dc = {0,-1,1,0};
string dir = "DLRU";

void rat(int row, int col, int n, string &current, vector<vector<bool>> &visited, vector<vector<int>> &maze){

    if(maze[0][0] == 0 || maze[n-1][n-1] == 0) return;

    if(row == n-1 && col == n-1){
        ans.push_back(current);
        return;
    }

    for(int i=0; i<4; i++){
        int nr = row + dr[i];
        int nc = col + dc[i];

        if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
        if(maze[nr][nc] == 0) continue;
        if(visited[nr][nc]) continue;

        current.push_back(dir[i]);
        visited[nr][nc] = true;
        rat(nr,nc,n,current,visited,maze);

        current.pop_back();
        visited[nr][nc] = false;
    }


}

int main(){
    vector<vector<int>> maze = {
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {1, 1, 0, 0},
    {0, 1, 1, 1}};
    
    int n = maze.size();

    vector<vector<bool>> visited(n,vector<bool>(n,false));
    visited[0][0] = true;  //imp

    string current;
    int row = 0;
    int col = 0;

    rat(row,col,n,current,visited,maze);   

    for(int i = 0; i<ans.size(); i++){
        cout<< ans[i]<<endl;
    }

return 0;
}
#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &mat, int target){
  int n = mat.size();
  int m = mat[0].size();

  int i = 0, j = m-1;
  while(i<n && j>=0){
    if(mat[i][j] > target){
    j--;
    }
    else if(mat[i][j] < target){
    i++;
    }
    else{
    return true;
    }
  }    
return false;

}
int main(){
    vector<vector<int>> mat = {
        {1,4,7,11},
        {2,5,8,12},
        {3,6,9,16},
        {10,13,14,17}
    };
    int target = 2;

    cout << searchMatrix(mat, target);

return 0;
}
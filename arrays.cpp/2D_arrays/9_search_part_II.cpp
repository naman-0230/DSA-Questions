#include<iostream>
#include<vector>
using namespace std;

bool BsearchMatrix(vector<vector<int>> &mat, int target){
  int n = mat.size();
  int m = mat[0].size();

  int low = 0, high = n*m -1;
 while(low <= high){
    int mid = low + (high - low)/2;
    int j = mid % m;
    int i = mid / m; 

    if(mat[i][j] == target){
        return true;
    }
    else if(mat[i][j] > target){
        high = mid - 1;
    }
    else{
        low = mid + 1;
    }
    
}

return false;

}
int main(){
    vector<vector<int>> mat = {
         {1,3,5},
        {7,9,11},
        {13,15,17}
    };
    int target = 7;

    cout << BsearchMatrix(mat, target);

return 0;
}
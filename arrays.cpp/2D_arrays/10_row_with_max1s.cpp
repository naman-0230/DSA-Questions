#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int BsearchMatrix(vector<vector<int>> &mat){        ////rows are given SORTED
  int n = mat.size();
  int m = mat[0].size();

  int max_count = 0; int row_i = -1;

  for(int i=0; i<n; i++){

   int low = 0, high = m-1;

   while(low<=high){
    int mid = low + (high - low)/2;
    if(mat[i][mid]==1){
      high = mid - 1;
    }
    else{
      low = mid + 1;
    }
    }
   int count_1 = m - low; 
  
   if(count_1 > max_count){
    max_count = count_1;
    row_i = i;
    }
}
return row_i;

}
int main(){
    vector<vector<int>> mat = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    cout << BsearchMatrix(mat);

return 0;
}
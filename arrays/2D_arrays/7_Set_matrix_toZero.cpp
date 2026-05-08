 #include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>> matrix = {
      {1,2,3,4},
      {5,0,7,8},
      {0,10,11,12},
      {13,14,15,0}
};
 int n = matrix.size();
    int m = matrix[0].size();

    bool col0 = true;

    // Step 1: Mark
    for(int i = 0; i < n; i++){
        if(matrix[i][0] == 0) col0 = false;

        for(int j = 1; j < m; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Step 2: Fill (reverse)
    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 1; j--){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }

        if(col0 == false){
            matrix[i][0] = 0;
        }
    }
for(auto &x :matrix){
    for(int v: x){
      cout<<v<< " ";
    }
    cout<<endl;
}   

return 0;
}
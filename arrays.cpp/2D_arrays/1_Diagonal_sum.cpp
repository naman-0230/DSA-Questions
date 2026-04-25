#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>> mat = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
};

    int mainDiag = 0, secDiag = 0;
    int n = mat.size();
    
    for(int i = 0; i < n; i++){
        mainDiag += mat[i][i];
        secDiag += mat[i][n - i - 1];   /////imp second diagonal condition
    }
    
    cout << "Main = " << mainDiag << endl;
    cout << "Secondary = " << secDiag << endl;

return 0;
}
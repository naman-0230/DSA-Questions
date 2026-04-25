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

for(int i=0; i<mat.size(); i++){
    for(int j=i; j<mat[0].size(); j++){    // remember to put j=i pr j=i+1; to avoid swapping again and again 
        swap(mat[j][i], mat[i][j]);
    }
}

for(auto &x: mat){
    for(int v: x){
        cout<<v;
    }
cout<<endl;
}

return 0; 
}
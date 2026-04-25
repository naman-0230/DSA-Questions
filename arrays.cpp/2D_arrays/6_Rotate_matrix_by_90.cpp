#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>> mat = {
    {1,2,3},
    {4,5,6},
    {7,8,9}       /// for rotation  1. can do in different answer matrix 
};                ///                  this works for rectangular matrix too so good                     
                  ///               2. can do in-place like the one i did
                  ///                  but it is only applicable for square matrix (preferred if given square matrix)

// transposing now                
for(int i=0; i<mat.size(); i++){
    for(int j=i; j<mat[0].size(); j++){    // remember to put j=i pr j=i+1; to avoid swapping again and again 
        swap(mat[j][i], mat[i][j]);
    }
 }

 // reversing each row
for(int i=0; i<mat.size(); i++){
    for(int j=0; j < (mat[0].size())/2 ; j++){      // now imp is to check j < matsize/2
        swap(mat[i][j+ (mat[0].size()-1-j)] , mat[i][j]);     // imp too j+ n-1-j
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
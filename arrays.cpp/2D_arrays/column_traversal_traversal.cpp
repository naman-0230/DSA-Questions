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
for(int j=0; j<mat[0].size(); j++){
    if(j%2 == 0){ 
      for(int i=0; i<mat.size(); i++){
       ans.push_back(mat[i][j]);
       }
     }
    else{
        for(int i= mat.size()-1 ; i>=0; i--){
       ans.push_back(mat[i][j]);
       }
      
    } 
   }

for(int x :ans){
    cout<< x<< " ";
}   

return 0;
}
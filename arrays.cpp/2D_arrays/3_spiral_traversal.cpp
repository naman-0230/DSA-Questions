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
//mian concept is to set boundaries..
int top = 0, bottom = mat.size()-1, left = 0, right = mat[0].size()-1; 

while(left<=right && top<=bottom){
for(int j=left; j<=right; j++){
    ans.push_back(mat[top][j]);
}
top++;

for(int i= top; i<=bottom ; i++){
    ans.push_back(mat[i][right]);
}
right--;
if(top<=bottom){                    /// other thing i can do .. main is to remember this if conditions
for(int j= right; j>=left; j--){
    ans.push_back(mat[bottom][j]);
}
bottom--;
}

if(left<=right){
for(int i= bottom; i>=top; i--){
    ans.push_back(mat[i][left]);
}
left++;
}
}



for(int x :ans){
    cout<< x<< " ";
}   

return 0;
}
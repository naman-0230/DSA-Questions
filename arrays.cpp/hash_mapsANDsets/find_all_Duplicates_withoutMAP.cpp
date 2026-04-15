#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
int main(){

vector<int> v ={3,4,1,2,6,4,7,5,6,7,4};

vector<int> ans;
for(int i=0; i< v.size(); i++){
    int j= abs(v[i])-1;                                

    if(v[j]<0){
        ans.push_back(abs(v[i]));
    }
    else   
    v[j]= -v[j];                  //imp concept
}

for(int x : ans){
    cout<< x;
}


return 0;
}
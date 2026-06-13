#include<iostream>
#include<vector>
using namespace std;
vector<int> store1toN(int n){
    if(n==0) return {};
    vector<int> ans = store1toN(n-1);
    ans.push_back(n);
    
    return ans;
}

int main(){
    int n = 6;
    vector<int> res = store1toN(n);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
return 0;
}
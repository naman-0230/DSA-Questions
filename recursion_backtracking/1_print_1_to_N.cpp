#include<iostream>
#include<vector>
using namespace std;

void print1toN(int n, vector<int> &v){
    if(n==0) return;
    print1toN(n-1, v);
    v.push_back(n);
}
int main(){
int n = 5;
vector<int>store;
print1toN(n,store);

for(int i=0; i<store.size(); i++){
    cout<<store[i]<<" ";
}

return 0;
}
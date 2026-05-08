#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    vector<int>v = {2,3,4,5,2,4,5,7,3};
    unordered_map<int, int> m;

    for(int i=0; i<v.size(); i++){
        m[v[i]]++;
    }
    for(auto x : m){
        cout<<x.first<<" "<<x.second<<endl;
    }


return 0;
}
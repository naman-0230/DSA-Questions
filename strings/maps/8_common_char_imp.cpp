#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;
vector<char> commonChar(vector<string> &v){
    vector<char> ans;
    unordered_map<char, int> m;
    for(char c: v[0]){
        m[c]++;
    }

    for(int i=1; i<v.size(); i++){
       unordered_map<char, int> temp;
       for(char c: v[i]){
        temp[c]++;
       }
       for(auto &x : m){
        x.second = min(x.second , temp[x.first]);              ///imp concept
       }
    }
    for(auto &x : m){
        while(x.second > 0){
            ans.push_back(x.first);
            x.second--;
        }
    }

    return ans;
}

int main(){
vector<string> v = {"bella","label","roller"};

vector<char> res = commonChar(v);
for(char c: res){
    cout<<c<<" ";
}

return 0;
}
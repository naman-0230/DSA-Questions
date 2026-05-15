#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;
vector<char> duplicates_InOrder(string &s){
    vector<char> ans;
    unordered_map<char, int> m;
    unordered_map<char, bool> used;
    for(char c: s){
        m[c]++;
    }
    for(char c: s){
        if(m[c] > 1 && !used[c]){
            ans.push_back(c);
            used[c] = true;
        }
    }
    return ans;
}
int main(){
string s = {"programming"};
vector<char> res = duplicates_InOrder(s);
for(char c: res){
    cout<<c<<" ";
}

return 0;
}
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string> &v){
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> m;

    for(string word: v){
        string temp = word;
        sort(temp.begin(), temp.end());
        m[temp].push_back(word);
    }
    for(auto &x: m){
        ans.push_back(x.second);
    }
    return ans;
}
int main(){
vector<string> v = {"eat","tea","tan","ate","nat","bat"};

vector<vector<string>> result = groupAnagrams(v);

for(int i=0; i < result.size(); i++){
    for(int j=0; j < result[i].size(); j++){
        cout<<result[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}
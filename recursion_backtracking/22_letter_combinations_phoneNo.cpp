#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

void combinations(string &s, int idx, string &curr, vector<string> &ans){
    vector<string> mp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    if(curr.size() == s.size()){
        ans.push_back(curr);
        return;
    }
    string letters = mp[s[idx]-'0'];
    for(int i = 0; i < letters.size(); i++){
        curr.push_back(letters[i]);
        combinations(s,idx+1,curr,ans);
        curr.pop_back();
    }
    
}

int main(){
    string s = "23";
    string curr;
    vector<string> ans;

    combinations(s,0,curr,ans);

    for(int i = 0; i < ans.size(); i++){
        cout<< ans[i]<<endl;
    }

return 0;
}
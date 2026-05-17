

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;
vector<int> isMatching(string &s, string &target){

    if(target.size() > s.size()) return {};
    vector<int> ans;

    int k = target.size();
    unordered_map<char, int> m1;
    unordered_map<char, int> m2;

    for(char c: target){
        m1[c]++;
    }

    for(int i = 0; i< k; i++){
        m2[s[i]]++;
    }
    if(m2 == m1){
        ans.push_back(0);
    }

    for(int i = k; i<s.size(); i++){
        m2[s[i]]++;
        m2[s[i-k]]--;
        if(m2[s[i-k]] == 0) m2.erase(s[i-k]);

        if(m2 == m1) ans.push_back(i-k+1);
    }
    return ans;
}

int main(){
    string s = {"csdsdlkkfjeif"};
    string target = {"eij"};

    vector<int> res = isMatching(s, target);
    for(int x: res){
        cout<< x<<" ";
    }

return 0;
}
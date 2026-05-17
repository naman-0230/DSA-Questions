#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<unordered_map>
using namespace std;
vector<int> count_distinct(string &s, int k){
    if(k > s.size()) return {};

    vector<int> ans;

    unordered_map<char, int> m;
    
    for(int i=0; i<k; i++){
        m[s[i]]++;
    }
    ans.push_back(m.size());

    for(int i=k; i< s.size(); i++){
        m[s[i]]++;
        m[s[i-k]]--;
        if(m[s[i-k]] == 0) m.erase(s[i-k]);
        ans.push_back(m.size());
    }
    return ans;
}

int main(){
    string s = {"fiifaodaf"};
    int k = 5;

    vector<int> res = count_distinct(s, k);

    for(int x: res){
        cout<<x<<" ";
    }
return 0;
}
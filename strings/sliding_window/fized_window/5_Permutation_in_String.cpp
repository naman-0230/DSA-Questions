// You are given:
// string s1
// string s2
// Return: true if:
// some permutation of s1
// exists as a substring in: s2

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;
bool isMatching(string &s, string &target){
    if(target.size() > s.size()) return false;

    int k = target.size();
    unordered_map<char, int> m1;
    unordered_map<char, int> m2;

    for(char c: target){
        m1[c]++;
    }

    for(int i = 0; i< k; i++){
        m2[s[i]]++;
    }
    if(m2 == m1) return true;

    for(int i = k; i<s.size(); i++){
        m2[s[i]]++;
        m2[s[i-k]]--;
        if(m2[s[i-k]] == 0) m2.erase(s[i-k]);

        if(m2 == m1) return true;
    }
    return false;
}

int main(){
    string s = {"csdsdlkkfjeif"};
    string target = {"eij"};

    cout<< isMatching(s, target);

return 0;
}
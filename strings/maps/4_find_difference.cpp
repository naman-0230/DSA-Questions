#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;
char extraChar(string &s, string &t){
    unordered_map <char, int> m;
    if(s.size() >= t.size()) return '\0';
    for(char c:t){
        m[c]++;
    }
    for(char c:s){
        m[c]--;
    }
    for(auto &x : m){
        if(x.second > 0) return x.first;
    }
    return '\0';
}

int main(){
string s = {"calloctety"};
string t = {"ctetycallco"};

cout<< extraChar(s, t);
return 0;
}
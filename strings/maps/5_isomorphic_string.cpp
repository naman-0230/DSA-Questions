#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;
bool isIsomorphic(string &s, string &t){
    if(s.size() != t.size()) return false;

    unordered_map <char, char> m;
    unordered_map <char, char> f;
    int i = 0;
    int j = 0;
    while(i < s.size() && j < t.size()){
    if(m.find(s[i]) != m.end()){
        if(m[s[i]] != t[j]) return false;
    }
    if(f.find(t[j]) != f.end()){
        if(f[t[j]] != s[i]) return false;
    }
    m[s[i]] = t[j];
    f[t[j]] = s[i];
    i++;
    j++;
    }

    return true; ///better to use freq array its faster as we are only dealing with characters (256 size)
}

int main(){
string s = {"bar"};
string t = {"foo"};
cout<< isIsomorphic(s, t);
return 0;
}
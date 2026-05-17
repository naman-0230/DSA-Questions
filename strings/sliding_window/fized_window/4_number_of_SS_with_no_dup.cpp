#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;
int countOf_substrings(string &s, int k){

    if(k > s.size()) return 0;
    int countSS = 0;
    unordered_map<char, int> m;

    for(int i = 0; i< k; i++){
        m[s[i]]++;
    }
    if(m.size() == k) countSS++;

    for(int i = k; i< s.size(); i++){
        m[s[i]]++;
        m[s[i-k]]--;
        if(m[s[i-k]] == 0) m.erase(s[i-k]);

        if(m.size() == k) countSS++;
    }
    return countSS;
}

int main(){

string s = {"sothisishollyofc"};
int k = 5;

cout<<countOf_substrings(s, k);

return 0;
}
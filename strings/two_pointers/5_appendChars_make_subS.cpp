// You are given two strings: s and t
// Return:
// minimum number of characters
// that must be appended to:
// end of s
// so that:
// t becomes a subsequence of s

// Subsequence?
// Characters appear:
//     in same order
//     not necessarily continuous
// Example:
// "ace"
// is subsequence of:
// "abcde"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int charAppend(string &s, string &t){
    int i = 0;
    int j = 0;
    while(i < s.size() && j < t.size()){
        if(s[i] == t[j]){
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    return (t.size() - j);
}
int main(){
string s = {"zacbbsd"};
string t = {"abcde"};

cout<<charAppend(s,t);

return 0;
}
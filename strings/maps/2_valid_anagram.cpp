#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;

//basic approach by 2 maps
bool validAnagram(string &a, string&b){
    if(a.size() != b.size()) return false;

    unordered_map<char, int> m1;
    for(char c:a){
        m1[c]++;
    }
    unordered_map<char, int> m2;
    for(char c:b){
        m2[c]++;
    }
    if(m1 == m2) return true;
    else  return false;
}
//main approach by using 1 map
bool validAnagramOptimized(string &a, string&b){
    if(a.size() != b.size()) return false;

    unordered_map<char, int> m1;
    for(char c:a){
        m1[c]++;
    }
    for(char c:b){
        m1[c]--;
    }
    for(auto &x: m1){
        if(x.second != 0) return false;
    }
    return true;
}

int main(){
string a ={"listen"};
string b ={"siLent"};
cout<< validAnagramOptimized(a,b);
return 0;
}


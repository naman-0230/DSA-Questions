#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;
bool ransom_note(string &a, string&b){
    unordered_map<char, int> m;
    if(a.size() < b.size()) return false;
    for(char c:a){
        m[c]++;
    }
    for(char c:b){
        m[c]--;
        // if(m[c] < 0) return false;   optimized moreeee
    }
    for(auto &x : m){
        if(x.second < 0) return false;
    }
    return true;
}
int main(){
string magazine ={"calat"};
string ransom ={"caaat"};
cout<< ransom_note(magazine , ransom);

return 0;
}
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;
vector<char> printDuplicates(string &s){
    vector<char>ans;
    unordered_map<char, int> m;
    for(int i=0; i<s.size(); i++){
    m[s[i]]++;
    }
    
    for(auto x : m ){
        if(x.second > 1){
            ans.push_back(x.first);
        }
    }

    return ans;
}
int main(){
string s = {"ssfdhhtfffhed"};
vector<char> res = printDuplicates(s);
for(char c:res){
    cout << c<< " ";
}
return 0;
}
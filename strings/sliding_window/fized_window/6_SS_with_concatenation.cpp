// You are given:
// string s
// list of words words (all same length)

// Find all starting indices where:
// a substring is formed by concatenating all words exactly once
// without any gaps or extra characters.

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<stack>
#include<unordered_map>
using namespace std;
vector<int> concatenationSS(string &s, vector<string> &target){

    vector<int> ans;
    int words_size = target[0].size();
    int words = target.size();
    int k = words_size * words;

    unordered_map<string, int> need;

    for(int i=0; i<target.size(); i++){            ///this is not space optimal ... that one is hard level 

        need[target[i]]++;
    }
    
    for(int i=0; i<= s.size()-k ; i++){            ///imp loop main
        
        unordered_map<string, int> m;
        for(int j=i; j< i+k; j+= words_size){      ///imp loop mainn

            string temp = s.substr(j, words_size);
            m[temp]++;
        }

        if(m == need){
            ans.push_back(i);
        }
    }




    return ans;
}

int main(){

string s = {"foobarsderbarfoo"};
vector<string> target = {"foo","bar"};

vector<int> res = concatenationSS(s, target);

for(int x: res){
    cout<<x<<" ";
}

return 0;
}
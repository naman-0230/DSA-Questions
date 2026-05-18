#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;
int lengthOfSS(string &s, int k){

    int max_length = 0;
    int length = 0;
    int j = 0;
    unordered_map<char, int> m;

    for(int i =0; i< s.size(); i++){

        m[s[i]]++;
        
        
        while(m.size() > k){
            
            m[s[j]]--;
            if(m[s[j]]==0) m.erase(s[j]);
            j++;
        }
        
        length = i-j+1;
        max_length = max(max_length, length);
    }
    return max_length;
}

int main(){
string s = {"aaabbbccddeeeeffffggghhh"};
int k = 3;

cout << lengthOfSS(s, k);

return 0;
}
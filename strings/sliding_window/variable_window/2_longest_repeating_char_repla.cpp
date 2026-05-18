#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;
int window_size(string &s, int k){
    int max_freq = 0;
    int freq = 0;
    int length = 0;
    int max_length = 0;
    int j = 0;

    unordered_map<char, int> m;

    for(int i=0; i<s.size(); i++){
        
        m[s[i]]++;
        freq = m[s[i]];
        max_freq = max(max_freq, freq);
        length = i-j+1;

        if(length - max_freq > k){
           m[s[j]]--; 
           j++;
        }
        length = i-j+1;
        max_length = max(max_length, length);
    }
    return max_length;
}

int main(){
string s = {"aabaabbbaaccbaa"};
int k = 3;

cout<< window_size(s, k);

return 0;
}
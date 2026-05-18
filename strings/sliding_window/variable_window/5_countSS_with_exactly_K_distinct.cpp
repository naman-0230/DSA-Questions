#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;
int countSS(string &s, int k){
    int j = 0;
    int count = 0;
    unordered_map<char, int> m;

    for(int i=0; i<s.size(); i++){
        
        m[s[i]]++;
        
        while(m.size() > k){

            m[s[j]]--;
            if(m[s[j]] == 0) m.erase(s[j]);

            j++;
        }
        count += i-j+1;     //usual count for <=k thingy in variable window
    }
    return count;
}

int main(){
    string s = {"aaabbbccddeeeeffffggghhh"};
    int k = 3;

    cout<< countSS(s, k) - countSS(s, k-1);     //imp for exactly k
    
    
return 0;
}
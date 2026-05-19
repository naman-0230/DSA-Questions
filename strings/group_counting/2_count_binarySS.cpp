// Given a binary string:
// Return:
// number of substrings such that:

// substring has equal number of 0s and 1s
// all 0s are grouped together
// all 1s are grouped together

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<stack>
#include<unordered_map>
using namespace std;

int countSS(string &s){

    int ans = 0;                     //count of SS
    int prev = 0, curr = 1;          //count of previous group and current one

    int i = 0, j = 1;

    while(j <= s.size()){

        if(j == s.size() || s[j] != s[i]){
            
            ans += min(prev, curr);
            i=j;
            j++;
            prev = curr;
            curr = 1;
        }
        else{
            j++;
            curr++;
        }
    
    }

    return ans;
}

int main(){
string s = {"0001111001001101"};

cout<< countSS(s);

return 0;
}
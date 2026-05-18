#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<unordered_map>
using namespace std;
int lengthSS(string &s){      

    int max_length = 0;
    int length = 0;
    int j = 0;
    unordered_map<char, int> m;

    for(int i=0; i<s.size(); i++){
        m[s[i]]++;
        
        while(m[s[i]] > 1){
            m[s[j]]--;
            j++;
        }
        length = i-j+1;
        max_length = max(max_length, length);
    }
    return max_length;
}

int main(){
string s = {"kvdrhbgcclvsvvwiolvkn"};
cout<<lengthSS(s);

return 0;
}
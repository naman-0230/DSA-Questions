#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<stack>
#include<unordered_map>
using namespace std;
int length_consecutive(string &s, int k){
    int max_length = 0;
    int length = 0;
    int j = 0, count = 0;
    
    for(int i=0; i<s.size(); i++){

        if(s[i] == '0') count++;

        while(count > k){
            if(s[j] == '0') count--;
            j++;
        }

        length = i-j+1;
        max_length = max(max_length, length);
    }

    return max_length;
}

int main(){
string s = {"100101010011011011"};
int k = 2;

cout<< length_consecutive(s, k);

return 0;
}
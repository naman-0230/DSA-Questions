#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<unordered_map>
using namespace std;
int lengthSS(string &s){      

    int max_length = 0;
    int length = 0;
    unordered_map<char, int> m;
    deque<int> dq;

    for(int i=0; i<s.size(); i++){
        m[s[i]]++;

        while(!dq.empty() && m[s[i]] > 1){
            int x = dq.front();
            m[s[x]]--;
            dq.pop_front();
            length--;
        }

        if(m[s[i]] <= 1){
            dq.push_back(i);
            length++;
        }
        max_length = max(max_length, length);
        
    }
    return max_length;
}

int main(){
string s = {"kvdrhbgcclvsvvwiolvkn"};
cout<<lengthSS(s);

return 0;
}






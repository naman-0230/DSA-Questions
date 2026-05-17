#include<iostream>
#include<vector>
#include<string>
#include<deque>
using namespace std;
bool isVowel(char c){
    c= tolower(c);
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return true;
    }
    else return false;
}

vector<int> max_vowels(string &s, int k){
    vector<int> ans;
    deque<int> dq;
    int count = 0;
    for(int i=0; i < k ; i++){
        if(isVowel(s[i])){
            dq.push_back(i);
            count++;
        }
    }
    ans.push_back(count);

    for(int i=k ; i< s.size(); i++){
        while(!dq.empty() && dq.front() <= i-k){
            dq.pop_front();
            count--;
        }
        if(isVowel(s[i])){
            dq.push_back(i);
            count++;
        }
        ans.push_back(count);
    }

    return ans;
}

int main(){
string s = {"hiihisiswhatitis"};
int k = 4;

vector<int> res = max_vowels(s, k);

for(int x: res){
    cout<< x<<" ";
}
return 0;
}
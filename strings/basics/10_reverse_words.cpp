#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<sstream>
#include<algorithm>
using namespace std;
vector<string> reverseWords(string &s){
vector<string> ans;

stringstream ss(s);
string word;
while(ss >> word){
    ans.push_back(word);
}

reverse(ans.begin(), ans.end());

return ans;
}

int main(){
string s = {"i love playing guitar"};

vector<string> res = reverseWords(s);
for(int i=0; i<res.size(); i++){
 cout<< res[i]<<" ";
}

return 0;
}
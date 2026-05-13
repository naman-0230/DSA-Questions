#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;
int main(){
string s ={"aaabcdddefgg"};
unordered_map<char, int> m;

for(char c:s){
    m[c]++;
}
for(auto x:m){
    cout<<(x.first)<<" "<<x.second<<endl;
}

return 0;
}
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<stack>
#include<unordered_map>
using namespace std;
int countSS(string s) {
    vector<int>v(3,0);

    int count=  0;

    int i = 0;

    for(int j=0; j<s.size(); j++){

        v[s[j]-'a']++;

        while (v[0]>0 and v[1]>0 and v[2]>0){ // if substring is valid

            count += s.size()-j;
            v[s[i]-'a']--;
            i++;

        }// substring is now invalid
            // count+=i; // so why do i add when substring is invalid
    }
    return count;
}
int main(){
string s = {"abcabaaaccccbccaaabc"};
    cout<< countSS(s);


return 0;
}


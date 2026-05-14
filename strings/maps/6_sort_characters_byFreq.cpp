#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
string sortByFrequency(string &s){
    string ans;
    unordered_map<char, int> m;
    for(char c:s){
        m[c]++;
    }
    vector<pair<int, char>> pairs;            ///better than priority heap if you wanna sort full
    for(auto &x: m){
        pairs.push_back({x.second , x.first});
    }
    sort(pairs.begin(), pairs.end(), greater<>());

    for(auto &x: pairs){
    ans.append(x.first, x.second);
    }
    return ans;
}
int main(){
string s = {"catsoffood"};
cout<< sortByFrequency(s);

return 0;
}
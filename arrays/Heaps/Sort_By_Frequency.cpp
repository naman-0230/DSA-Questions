#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
vector<int> v = {1,1,4,3,2,5,3,4,2,4,1,1,1};

vector<int> ans;
unordered_map<int,int> m; 

for(int i=0; i< v.size(); i++){
    m[v[i]]++;
}
priority_queue<pair<int,int>> pq;
for(auto x : m){
 pq.push({x.second,x.first});
}
   while(!pq.empty()){                                       
    ans.push_back(pq.top().second);
    pq.pop();
}

for(int x : ans){
    cout<<x<<" ";
}

return 0;
}
/////////// if wanna do sorting then this ... actually this is more optimal one 
// vector<pair<int,int>> freq;

// for(auto x : m){
//     freq.push_back({x.second, x.first}); // (frequency, element)
// }

// sort(freq.begin(), freq.end(), greater<>());
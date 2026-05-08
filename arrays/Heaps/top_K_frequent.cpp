#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
vector<int> v = {1,1,4,3,2,5,3,4,2,4,1,1,1};
int k=3;

vector<int> ans;
unordered_map<int,int> m; 

for(int i=0; i< v.size(); i++){
    m[v[i]]++;
}

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

for(auto it : m){
    pq.push({it.second,it.first});     ///pushing pair onto heap as it will have v[i] saved
    if(pq.size()>k){                   // normal min heap logic to get k largest element
        pq.pop();
    }
}
while(!pq.empty()){
    ans.push_back(pq.top().second);
    pq.pop();
}

reverse(ans.begin(), ans.end());      // as outout will give in reverse order so to fix it

for(int x:ans){
 cout<< x<<" ";
}
return 0;
}
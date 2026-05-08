#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
vector<int> v = {2,3,6,6,3,7,9,3,2};
int k = 3; 
vector<int>ans;
priority_queue<pair<int,int>> pq;

for(int i=0; i<k; i++){
    pq.push({v[i], i});
}
ans.push_back(pq.top().first);

for(int i = k; i< v.size(); i++){
 while(!pq.empty() && pq.top().second <= i-k){   //removing elements  only care about top as its max and will affect the result
    pq.pop();
 }
 pq.push({v[i], i});                             //new element

 ans.push_back(pq.top().first);                  // pushing it to ans vector

}

for(int x : ans){
    cout<<x<<" ";
}

return 0;
}

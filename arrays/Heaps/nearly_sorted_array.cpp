#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
   vector<int> v = {6, 5, 3, 2, 8, 10, 9};
   int k = 3;
   
 priority_queue<int, vector<int>, greater<int>> pq;

    vector<int> ans;

    // first k+1 elements
    for(int i = 0; i <= k; i++) {
        pq.push(v[i]);
    }

    // process remaining
    for(int i = k+1; i < v.size(); i++) {
        ans.push_back(pq.top());
        pq.pop();

        pq.push(v[i]);
    }

    // remaining heap
    while(!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }

    for(int x : ans) cout << x << " ";
    

    return 0;
}









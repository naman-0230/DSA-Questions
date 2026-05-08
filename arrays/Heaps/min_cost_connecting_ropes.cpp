// Problem
// 👉 Minimum Cost to Connect Ropes

// Given rope lengths:
// v = [l1, l2, l3, ...]

// 👉 You can connect any two ropes:

// Cost = sum of their lengths
// New rope = combined length
// 🎯 Goal

// 👉 Connect all ropes into one
// 👉 Minimize total cost


#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
vector<int> v = {3,4,1,2,7,8,5,3,9};              // we connect smallest 2 ropes and push it back

priority_queue<int,vector<int>,greater<int>> pq (v.begin(),v.end());
int cost =0;

while(pq.size()>1){
 int a= pq.top();
 pq.pop();
 int b= pq.top();
 pq.pop();
 cost += a+b;
 pq.push(a+b);
}

cout<<cost;
return 0;
}


#include<iostream>
#include<vector>
#include<deque>
#include<climits>
using namespace std;

int main(){
 vector<int> v ={2,3,5,1,-2,4,5,3,-7,8,2,3,1};
int k = 3;

vector<int> ans;
deque<int> dq;
// for first k
for(int i=0; i<k; i++){
   
    while(!dq.empty() && v[dq.back()] <= v[i]){
        dq.pop_back();
    }
    dq.push_back(i);
}
ans.push_back(v[dq.front()]);

for(int i=k; i< v.size(); i++){
    while(!dq.empty() && dq.front() <= i-k){
        dq.pop_front();
    }

     while(!dq.empty() && v[dq.back()] <= v[i]){
        dq.pop_back();}

    dq.push_back(i);
  ans.push_back(v[dq.front()]);
}

for(int x : ans){
    cout<<x<<" ";
}
}
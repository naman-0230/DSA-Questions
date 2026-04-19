#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
vector<vector<int>> v = {{1,3},{-2,2},{5,8},{0,1}};
int k=2;

    //distance from origin will be sqrt of x2 + y2 but sqrt not needed as we just comparing 
priority_queue<pair<int,int>> pq; 

for(int i=0; i< v.size(); i++){
    int d = v[i][0]*v[i][0] + v[i][1]*v[i][1];
    pq.push({d,i});
    
    if(pq.size()>k){
        pq.pop();
    }
}
// if i want index only 
// vector<int> ans;  

// while(!pq.empty()){
//     ans.push_back(pq.top().second);
//     pq.pop();
// }

// reverse(ans.begin(),ans.end());

// for(int x: ans){
//     cout<<x<<" ";
// }

// return 0;
// }
// if i want actual value 

vector<vector<int>> ans;  

while(!pq.empty()){
    ans.push_back(v[pq.top().second]);
    pq.pop();
}

reverse(ans.begin(),ans.end());

for(auto &x: ans){
    cout<<"["<< x[0]<<","<<x[1]<<"]";
}

return 0;
}
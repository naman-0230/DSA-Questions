#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;
 
int main(){
 
    vector<vector<int>> v = {
        {1,4,7},
        {2,5,8},
        {3,6,9}};
    
    vector<int>ans;
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;    
    
for(int i =0; i< v.size(); i++){
    pq.push({v[i][0] , i , 0});
}

while(!pq.empty()){
  auto t = pq.top();       //// unpacking the tuple// imp concept

int val = get<0>(t);
int arr = get<1>(t);
int idx = get<2>(t);

ans.push_back(val); 
pq.pop();
if(idx + 1  < v[arr].size()){                         //imp to see how we check inner arr size 
    pq.push({v[arr][idx+1], arr , idx+1});
}

}
   for(int x : ans){
    cout<< x;
   }

    return 0;
}
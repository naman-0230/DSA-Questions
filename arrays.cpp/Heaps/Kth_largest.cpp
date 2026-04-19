#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
vector<int> v = {0,2,3,1,6,3,5};
int k = 2;

priority_queue<int, vector<int>, greater<int>> pq;

for(int i=0; i< v.size(); i++){
    pq.push(v[i]);
    if(pq.size()>k){
        pq.pop();
    }
}
cout<< pq.top();

return 0;
}
// for kth smallest

// priority_queue<int> pq;

// for(int i=0; i< v.size(); i++){
//     pq.push(v[i]);
//     if(pq.size()>k){
//         pq.pop();
//     }
// }
// cout<< pq.top();

// return 0;
// }

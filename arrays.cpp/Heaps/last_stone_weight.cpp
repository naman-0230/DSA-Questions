#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
vector<int> v = {0,2,3,1,6,3,5};
int a,b;

priority_queue<int> pq(v.begin(), v.end());

while(pq.size()>1){
a = pq.top();
pq.pop();
b = pq.top();
pq.pop();

  if(a>b){
  pq.push(a-b);
  }
}
if(!pq.empty()){
    cout<<pq.top();
}
else{
    cout<<"no elements remain";
}
 
return 0;
}
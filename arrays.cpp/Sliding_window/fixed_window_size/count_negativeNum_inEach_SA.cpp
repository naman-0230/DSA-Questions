#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int main(){
 vector<int> v ={2,-3,-5,1,-2,4,5,3,-7,8,2,3,1};
int k = 3;

vector<int> ans;
deque<int> dq;
int count = 0;

for(int i=0; i<k; i++){          //first k elements
   if(v[i]<0){
    dq.push_back(i);
    count++;
   }
}
 ans.push_back(count);

for(int i=k; i< v.size() ;i++){             //sliding window
 while(!dq.empty() && dq.front()<= i-k) {      // removing unnecessary elements
   dq.pop_front();
   count--;
 } 

 if(v[i]<0){                 //adding new elements
    dq.push_back(i);
    count++;
 }

 ans.push_back(count);                 //storing answer finally after each iteration
   
}

for(int x : ans){
   cout<< x<<" ";
}


return 0;
}
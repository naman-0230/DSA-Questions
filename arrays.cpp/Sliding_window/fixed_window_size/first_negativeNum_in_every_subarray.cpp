#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int main(){
 vector<int> v ={2,-3,-5,1,-2,4,5,3,-7,8,2,3,1};
int k = 3;

vector<int> ans;
deque<int> dq;
for(int i=0; i<k; i++){
   if(v[i]<0){
    dq.push_back(i);
   }
}
 if(!dq.empty()){
 ans.push_back(v[dq.front()]);
 }
 else{
   ans.push_back(0);
 }

for(int i=k; i< v.size() ;i++){             //sliding window
 while(!dq.empty() && dq.front()<= i-k) {      // removing unnecessary elements
   dq.pop_front();
 } 

 if(v[i]<0){                 //adding new elements
    dq.push_back(i);
 }

 if(!dq.empty()){                      //storing answer finally after each iteration
   ans.push_back(v[dq.front()]);
 }
 else{
   ans.push_back(0);
 }
 
 
}

for(int x : ans){
   cout<< x<<" ";
}


return 0;
}
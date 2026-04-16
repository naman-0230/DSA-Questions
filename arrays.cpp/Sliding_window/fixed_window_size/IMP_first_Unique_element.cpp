#include<iostream>
#include<vector>
#include<unordered_map>
#include<deque>
using namespace std;

int main(){
 vector<int> v ={2,4,3,2,3,5,1,3,4,6,5,5};
int k = 4;

vector<int> ans;
unordered_map<int, int> m;
deque<int> dq;

// for the first k elements
for(int i=0; i<k; i++){
  m[v[i]]++;
  
  dq.push_back(i);
  
} 
// cleanup of dq
while(!dq.empty() && m[v[dq.front()]] >1){     ///important concept//////                          
    dq.pop_front();
}

 if(!dq.empty()){
    ans.push_back(v[dq.front()]);}     // storing values
  else{
    ans.push_back(-1);
  }

// for sliding window
for(int i=k; i< v.size(); i++){
          //removing elements
          //important concept
    m[v[i-k]]--;     

     while(!dq.empty() && dq.front() <= i-k){
         dq.pop_front();
     }
    

    m[v[i]]++;

                         //adding new ones 
    dq.push_back(i);
    

    while(!dq.empty() && m[v[dq.front()]] >1){    ///cleanup
    dq.pop_front();
    }

  if(!dq.empty()){
    ans.push_back(v[dq.front()]);}     // storing values
  else{
    ans.push_back(-1);
  }
}

for( int x : ans){
    cout<<x<<" ";
}

return 0;
}
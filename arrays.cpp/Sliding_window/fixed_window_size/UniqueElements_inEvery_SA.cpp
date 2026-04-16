#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
 vector<int> v ={2,3,2,1,2,4,5,3,7,8,2,3,1};
int k = 3;

vector<int> ans;
unordered_map<int, int> m;

for(int i=0; i<k; i++){          //first k elements
  m[v[i]]++;
}

ans.push_back(m.size());

for(int i=k; i< v.size(); i++){

    m[v[i-k]]--;            //removing unnecessary elements
  if(m[v[i-k]]==0){
    m.erase(v[i-k]);
  }

  m[v[i]]++;                // adding new distinct values

ans.push_back(m.size());    // storing result 

}

for(int x : ans){           
   cout<< x<<" ";
}


return 0;
}
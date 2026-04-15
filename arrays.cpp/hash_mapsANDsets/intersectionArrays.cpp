#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main(){
 vector<int> v1 ={2,3,5,1,2,4};
 vector<int> v2 ={5,1,2,20};

    vector<int> ans;
    unordered_set<int> s(v1.begin(),v1.end());

   for(int i=0; i< v2.size(); i++){
    if(s.find(v2[i])!=s.end()){
        ans.push_back(v2[i]);
        s.erase(v2[i]);
    }
   }

   for(int i =0; i< ans.size(); i++){
    cout<< ans[i]<< " ";
   }


return 0;
}
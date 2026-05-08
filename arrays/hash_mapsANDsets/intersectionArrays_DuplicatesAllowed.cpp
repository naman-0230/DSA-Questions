#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
 vector<int> v1 ={2,3,5,1,2,4};
 vector<int> v2 ={5,1,2,1,20};

    vector<int> ans;
    unordered_map<int, int> m;

   for(int i=0; i< v1.size(); i++){
        m[v1[i]]++;
    }
    
    for(int i=0; i< v2.size(); i++){
       if(m[v2[i]]>0){
        ans.push_back(v2[i]);
        // decrease frequency little good logic here
        m[v2[i]]--;
       }
    }

   for(int i =0; i< ans.size(); i++){
    cout<< ans[i]<< " ";
   }


return 0;
}
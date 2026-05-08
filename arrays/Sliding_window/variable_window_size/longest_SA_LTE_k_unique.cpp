#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int lengthSA(vector<int> &v , int k){        /// this one is also known as 
unordered_map<int, int> m;                  //// fruits in basket problem 
 int j=0;
 int max_length = 0, length = 0; 
 
 for(int i=0; i< v.size(); i++){
    m[v[i]]++;
    while(m.size()>k){
        m[v[j]]--;
        if(m[v[j]]==0){
            m.erase(v[j]);
        }
        j++;      //always put j after that if condition
    }
    length = i-j+1;
    max_length = max(max_length, length);
 }
 

 return max_length;
}

int main (){
  vector<int> v ={1,2,0,1,1,0,3,0,1};
 int k=2;
 
 cout<<lengthSA(v,k);
    return 0;
}

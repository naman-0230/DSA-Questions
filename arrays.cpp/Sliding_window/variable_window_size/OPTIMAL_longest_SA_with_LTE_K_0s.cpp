#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int lengthSA(vector<int> &v , int k){
   
 int j=0;                         
 int max_length=0, length=0;
 int count=0;                    ///instead of map just use a counter////
 
 for(int i=0;i< v.size(); i++){
    if(v[i]==0){
        count++;
    }
    while(count > k){
        if(v[j]==0){
            count--;
        }
        j++;
    }

length = i-j+1;
// if(count==k)  --> when get asked exact k 0s .... for length cant do <=k then <=k-1 and subtract
max_length= max(max_length, length);

 }

 return max_length;
}

int main (){
  vector<int> v ={1,0,0,1,1,0,1,0,1};
 int k=2;
 
 cout<<lengthSA(v,k);
    return 0;
}

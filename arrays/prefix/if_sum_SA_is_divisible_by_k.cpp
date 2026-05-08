#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int countSA(vector<int> &v , int k){       // we need to return true/false if we have a SA atleast of Length 2
unordered_map<int, int> m;                

 int sum = 0;
int length = 0, max_length = 0;

   m[0] = -1;                       // length so its index = -1
 for(int i=0; i< v.size(); i++){
    sum += v[i];
    int rem = sum % k;

    if(rem< 0){           //imp negative remainder handling 
      rem += k;
    }
    if(m.find(rem - 0)!=m.end()){
      int j = m[rem - 0];
      length = i-j;
      max_length = max(max_length, length);
    }
    if(m.find(rem)==m.end()){
    m[rem]= i; 
    }                       
 }                                                  /////////NOT OPTIMAL SOLUTION////

 if(max_length > 1){                               ///////refer to optimal one /////
    return true;
 }
 return false;

}
int main (){
  vector<int> v ={1,2,0,1,1,0,3,0,1};
 int k=2;
 
 cout<<countSA(v,k);
    return 0;
}

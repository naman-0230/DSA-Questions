#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int countSA(vector<int> &v , int k){       
unordered_map<int, int> m;                

 int sum = 0;
int count = 0;

   m[0] = 1;                       // imp comdition for prefix[-1] = 0 
 for(int i=0; i< v.size(); i++){
    sum += v[i];
    int rem = sum % k;

    if(rem< 0){           //imp negative remainder handling 
      rem += k;
    }
    if(m.find(rem - 0)!=m.end()){
      count += m[rem - 0];
    }    
    m[rem]++;                           
 }
 return count;

}
int main (){
  vector<int> v ={1,2,0,1,1,0,3,0,1};
 int k=2;
 
 cout<<countSA(v,k);
    return 0;
}

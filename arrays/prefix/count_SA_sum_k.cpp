#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int countSA(vector<int> &v , int k){       
unordered_map<int, int> m;                
 int count = 0;
 int sum = 0;

 for(int i=0; i< v.size(); i++){
    sum += v[i];

    m[0] = 1;                       // imp comdition for prefix[-1] = 0 
    if(m.find(sum - k)!= m.end()){
        count += m[sum - k] ;           //imp count as map value decides how many times prefix(j) has appreared
    }                                   // and value means that much SA finished here having sum k so count can go wayy up
    m[sum]++;
 }
 return count;
}

int main (){
  vector<int> v ={1,2,0,1,1,0,3,0,1};
 int k=2;
 
 cout<<countSA(v,k);
    return 0;
}

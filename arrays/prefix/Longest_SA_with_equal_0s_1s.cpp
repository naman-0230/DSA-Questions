#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int lengthSA(vector<int> &v){       
unordered_map<int, int> m;                
 int max_length = 0, length = 0;
 int sum = 0;

 m[0]= -1;

 for(int i=0; i< v.size(); i++){
    if(v[i]==0){
    sum--;                //treating zero as -1 so can do sum+= -1 or simply sum--;
    }
    else{
       sum += v[i];      // normal prefix 
    }

    if(m.find(sum - 0)!= m.end()){            //since we want equal 0s 1s sum will become ==0 if we convert 0s to -1
        int j = m[sum - 0];                  
        length = i-j;
        max_length = max(max_length, length);
    }

   if(m.find(sum)==m.end()){
    m[sum] = i;
   }
 }

return max_length;
} 
int main (){
  vector<int> v ={1,1,0,1,1,0,0,0,1};
 
 cout<<lengthSA(v);
    return 0;
}

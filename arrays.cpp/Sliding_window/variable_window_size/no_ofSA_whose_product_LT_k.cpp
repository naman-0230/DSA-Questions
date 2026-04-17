#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){
 vector<int> v ={2,5,3,2,8,2,4,3};          //for WHEN input has no zeroes
 int k = 20;
if(k<1){
    cout<<"invalid k";
}
int count = 0;
long long product = 1;
int j=0;

for(int i=0; i< v.size(); i++){

   product *= v[i];
   
   while(product >= k && j<=i){     //j=i still in loop for condition where v[i]> k
    product/=v[j];
    j++;
   }

   count += i - j +1;        // most imp concept here
 
}
cout<< count;

return 0;
}
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){
 vector<int> v ={2,5,3,0,8,2,4,3,0,2,4,6,5};          //for WHEN input has ZEROES
 int k = 20;
if(k<1){
    cout<<"invalid k";
}
int count = 0;
long long product = 1;
int j=0;
int x=0;      //this pointer only for checking starting point of each non zero subarray
int SA_size;   // size of non zero subarray
int n = 0;      //no. of SA containing NO zeroes

int total = (v.size())*(v.size()+1)/2;     //total no. of SA

for(int i=0; i< v.size(); i++){
        // FOR ZERO HANDLING                        
  if(v[i]==0){

    SA_size= i-x;
    x = i+1;
   n += (SA_size)*(SA_size +1)/2;       //no. of SA without zero from till window reset

    j=x;     //resetting window  (splitting array in two and not looking back at the previous one)
    product = 1;                  //restting product as we reset window

    continue;                           // always continue instead of i++
  }                                    // as by continue you check for zero again 
                                       // essential when there are two or more zeroes simultaneously

   product *= v[i];
   
   while(product >= k && j<=i){     //j=i still in loop for condition where v[i]> k
    product/=v[j];
    j++;
   }

   count += i - j +1;        // imp concept here
}

 SA_size= (v.size())-x;               // for SA after last occurring zero till the end 
 
 n += (SA_size)*(SA_size +1)/2;       // adding this no. of SA to main total no.

 int n_with_z = total - n;            //total no. of SA with zeroes

count += n_with_z;                   // adding that to the count as all SA containing obviously will be <k

cout<< count;

return 0;
}
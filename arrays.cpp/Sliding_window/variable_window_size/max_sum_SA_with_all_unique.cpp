#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

int main(){
 vector<int> v ={1,-3,2,-1,2,4,-2,3,4,-2};
 unordered_map<int,int> m;

int sum= 0; int max_sum = INT_MIN;
int j=0;

for(int i=0; i< v.size(); i++){

    m[v[i]]++;

    sum += v[i];
    
    while(m[v[i]] > 1){            //important condition as shrinking window from 
        sum -= v[j];               // left automatically decrreases map i when dup is removed
        m[v[j]]--;   
        j++;
    }

    max_sum = max(sum, max_sum);

//     if(sum<0){
//         sum= 0;          //handling negatives contribution 
//         m.clear();       buttttt its not good, can give wrong output 
//         j= i+1;         thats why cant use kadane in this problem
//     }                
//          FOR NEGATIVE VALUES IN INPUT CASE, NEED ADVANCE METHODS (refer to VERY HARD1)

 }

cout<< max_sum;

return 0;
}
#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

int main(){
 vector<int> v ={2,5,3,2,8,2,4,3};
 int k=3;
 unordered_map<int,int> m;

int sum= 0; int max_sum = INT_MIN;
int j=0;

for(int i=0; i< v.size(); i++){

    m[v[i]]++;

    sum += v[i];
    
    while(m.size() > k){ 
        m[v[j]]--;                          
        sum -= v[j];  

        if(m[v[j]]==0){           //reduction of map size
            m.erase(v[j]);
        }
        j++;                   //last increment will be j as before doiing that will lead to false pointer
    }

    if(m.size()==k){
        max_sum = max(sum, max_sum);}  //only compute maxsum when its = k ;
                                        // when its < k, its not allowed
 }

cout<< max_sum;

return 0;
}
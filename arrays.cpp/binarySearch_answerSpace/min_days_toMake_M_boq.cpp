#include<iostream>
#include<vector>
#include<climits>
using namespace std;

bool isPossible(vector<int> &v, int m , int k , int mid){

    int count_bloom = 0;
    int count_boq = 0;
    for(int i=0; i< v.size(); i++){
        if(v[i] <= mid){
            count_bloom++;
            // if(count_bloom % k == 0){       old logic can work but little shaky
            //  count_boq++;
            // }
            if(count_bloom == k){             //new logic works little better
                count_boq++;
                count_bloom = 0;
            }
        }
        else{
            count_bloom = 0;
        }
    }
    return count_boq >= m;
    
}


int minVector(vector<int> &v){
    int minVector = INT_MAX;
    for(int i=0; i< v.size(); i++){
     minVector = min(minVector, v[i]);
    }
    return minVector;
}
int maxVector(vector<int> &v){
    int maxVector = 0;
    for(int i=0; i< v.size(); i++){
     maxVector = max(maxVector, v[i]);
    }
    return maxVector;
}


int minDays(vector<int> &v, int m, int k){

    int low = minVector(v);
    int high = maxVector(v);
    int ans = high;

    if(!isPossible(v,m,k,high)){
        return -1;
    }

    while(low<=high){
         int mid = low + (high-low)/2;
  
    if(isPossible(v,m,k,mid)){
        ans = mid;
        high = mid - 1;
    }
    else{
        low = mid + 1;
    }
    }
   return ans;
}


int main(){
vector<int> v ={1,10,3,10,2};
int m = 2;
int k = 2;

cout<< minDays(v,m,k);

return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int kth_missing(vector<int> &v , int k){
   int low = 0;
   int high = v.size()-1;

   while(low<=high){
    int mid = low + (high - low)/2;
    int missing = v[mid]-(mid+1);
    if(missing < k){
        low = mid + 1;
    }
    else{                        // we needed two indexes btw which missing number is
        high = mid - 1;          // after this high has become lower index , low has become higher index
    }
   }

//    int missing_high = v[high]-(high+1);
//    int more_missing = k - missing_high;          if high will be -1; it will crash
//    int ans = v[high] + more_missing;
//    return ans;

   return low + k;                //***imppppp   
}



int main(){
vector<int> v = {2,3,4,7,11};
int k = 5;

cout<< kth_missing(v,k);
return 0;
}
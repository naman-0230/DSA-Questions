#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> &v, int cows, int mid){
    int count_cows = 1;
    int last_placed = 0;         /// imp as it stores last stored cow location and track distance from that index
    for(int i = 1 ; i< v.size(); i++){
      if((v[i] - v[last_placed]) >= mid){
        last_placed = i;
        count_cows++;
        if(count_cows >= cows){
            return true;
        }
      }
  }
  return false;
}

int max_of_minD(vector<int> &v, int cows){

    int low = 0;           /// for duplicates otherwise low = 1 is fine too
    int high = v[v.size()-1] - v[0];
    int ans = low;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(isPossible(v, cows, mid)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}
int main(){
vector<int> v ={0,3,4,7,10,9};
int cows = 4;

sort(v.begin(), v.end());    ///imp to sort as elements are co-ordinates so consecutive cordinates will have least value of distance

cout<< max_of_minD(v, cows);

return 0;
}
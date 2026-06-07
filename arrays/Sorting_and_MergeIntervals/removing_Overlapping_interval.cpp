#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        int removed = 0;

        sort(intervals.begin(), intervals.end(),
        [](auto &a, auto&b){
            return a[1] < b[1];
        });

        int prevend = intervals[0][1];
        for(int i=1; i< intervals.size(); i++){
            if(intervals[i][0] < prevend){
                removed++;
            }
            else{
                prevend = intervals[i][1];
            }
        }
        return removed;
    }
int main(){
vector<vector<int>> v = {{1,2},{2,3},{3,4},{1,3}};
cout<< eraseOverlapIntervals(v);

return 0;
}

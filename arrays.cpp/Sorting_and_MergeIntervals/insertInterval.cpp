#include<bits/stdc++.h>
#include<vector>
using namespace std;

bool isSorted(vector<vector<int>> &intervals){
    for(int i=0; i<intervals.size()-1 ; i++){
        if(intervals[i][0]>intervals[i+1][0])
        return false;
    }
    return true;
}

vector<vector<int>> insertIntervals(vector<vector<int>> &intervals){
    vector<vector<int>> temp;

    if(intervals.size()==0) return temp;      // for empty intervals
  
    if(!isSorted(intervals)){
    sort(intervals.begin(),intervals.end());}         // sort only if sorting is needed

    temp.push_back(intervals[0]);
    for(int i=1; i<intervals.size(); i++){
        if(intervals[i][0] <= temp.back()[1]){
            temp.back()[1]= max(intervals[i][1], temp.back()[1]);
        }
        else{
            temp.push_back(intervals[i]);
        }
    }

  
return temp;
}
int main(){
 vector<vector<int>> intervals = {{1,3},{15,18},{2,2},{2,6},{8,10}};
 vector<int> newInterval = {10,13};

 intervals.push_back(newInterval);

 vector<vector<int>> ans = insertIntervals(intervals);
 for(auto &val : ans){
  cout << val[0]<<" "<< val[1]<<endl;
 }
}
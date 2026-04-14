#include<bits/stdc++.h>        //new header file
#include<vector>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){
    vector<vector<int>> temp;

    if(intervals.size()==0) return temp;      // for empty intervals
    sort(intervals.begin(),intervals.end());

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


 vector<vector<int>> ans = mergeIntervals(intervals);
 for(auto &val : ans){
  cout << val[0]<<" "<< val[1]<<endl;
 }
}
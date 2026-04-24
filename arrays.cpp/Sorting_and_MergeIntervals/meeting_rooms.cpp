// Meeting Rooms I (Feasibility Problem)
// 📌 Problem Statement

// You are given a list of meeting time intervals:

// intervals = [[start1, end1], [start2, end2], ...]

// 👉 Each interval represents a meeting with:

// start time
// end time
// ❓ Task

// Determine:

// Can a single person attend all meetings?


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

bool canAttendMeeting(vector<vector<int>> &intervals){

    if(intervals.size()==0) return true;      // for empty intervals
  
    if(!isSorted(intervals)){
    sort(intervals.begin(),intervals.end());}         // sort only if sorting is needed

    for(int i=1; i<intervals.size(); i++){
        if(intervals[i][0] < intervals[i-1][1]){
            return false;
        }
    }

    return true;
}

int main(){

 vector<vector<int>> intervals = {{1,3},{15,18},{8,10}};
 
 cout<<canAttendMeeting(intervals);

}
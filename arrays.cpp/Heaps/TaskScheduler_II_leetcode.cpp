#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
    vector<int> tasks = {1,2,1,2};
    int space = 2;

    unordered_map<int,long long> lastDay;

    long long day = 0;

    for(int t : tasks) {

        // if task seen before
        if(lastDay.find(t) != lastDay.end()) {
            long long nextAllowed = lastDay[t] + space + 1;
            if(day < nextAllowed) {
                day = nextAllowed;  // take breaks
            }
        }

        lastDay[t] = day;
        day++;  // move to next day
    }

    cout << day;
}
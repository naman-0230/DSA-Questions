// Problem Statement (clean)
// You are given:

// k → max number of projects you can pick
// w → initial capital

// Each project has:

// capital[i] → minimum capital required
// profit[i] → profit gained after completion
// 🎯 Goal

// 👉 Maximize final capital after doing at most k projects

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int k = 2, w = 2;
    vector<int> profits = {1,2,3,5,6};
    vector<int> capital = {0,1,1,6,8};

    // min heap based on capital
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minH;

    // max heap for profits
    priority_queue<int> maxH;

    // push all projects into min heap
    for(int i = 0; i < profits.size(); i++) {
        minH.push({capital[i], profits[i]});
    }

    while(k--) {

        // unlock all projects we can afford
        while(!minH.empty() && minH.top().first <= w) {
            maxH.push(minH.top().second);
            minH.pop();
        }

        // if no project available
        if(maxH.empty()) break;

        // pick most profitable
        w += maxH.top();
        maxH.pop();
    }

    cout << w;
    return 0;
}







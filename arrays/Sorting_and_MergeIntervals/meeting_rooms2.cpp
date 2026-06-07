#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;
int num(vector<vector<int>> &v){
    // if(v.size() == 0) return 0;
    // int count = 1;

    // for(int i = 1; i<v.size(); i++){
    //     bool nice = false;
    //     for(int j= 1; j <= i; j++){
    //         if(v[i-j][1] < v[i][0]) nice = true;
    //     }
    //     if(!nice) count++;
    // }
    // return count;
    if(v.size() == 0) return 0;
    int count = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    sort(v.begin(), v.end());

    for(int i = 0; i<v.size(); i++){
        if(!pq.empty() && pq.top() > v[i][0]){
            count++;
            pq.push(v[i][1]);
        }
        else{
            if(!pq.empty()) pq.pop();
            pq.push(v[i][1]);
        }
    }
    return count;

    // or we can do pq.size while only popping when pq.top() <= v[i][0]
}
int main(){
vector<vector<int>> v = {{0,30}, {20,35}, {32,40}};
cout<<num(v);

return 0;
}
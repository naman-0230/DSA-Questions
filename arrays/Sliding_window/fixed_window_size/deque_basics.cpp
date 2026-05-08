#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int main(){

    vector<int> v ={5,5,4,2,5,6,8};
    int k=3;
    deque<int> dq;
    
    dq.push_back(v[2]);
    dq.push_front(v[3]);
    dq.push_back(v[1]);
    dq.pop_front();
  
    for(auto x : dq){
        cout<<x<<" ";
    }
    cout<< endl;
    
    //reversing vector using deque
    dq.clear();
    for(int x :v){              // putting vector values on dq in reverse order
        dq.push_front(x);
    }

    for(auto x : dq){
        cout<<x<<" ";
    }
    

    return 0;
}
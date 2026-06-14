#include<iostream>
#include<vector>
using namespace std;

void subs(vector<int> &v, int idx, vector<int> &curr){

    if(idx == v.size()){
        for(int x: curr){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }

    curr.push_back(v[idx]);
    subs(v, idx+1, curr);

    curr.pop_back();

    subs(v, idx+1, curr);

}

int main(){

    vector<int> v={1,2,3};
    vector<int> curr = {};

    subs(v,0,curr);

return 0;
}
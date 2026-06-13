#include<iostream>
#include<vector>
using namespace std;
void rev(vector<int> &v, int i, int j){
    if(i>=j) return;
    swap(v[i], v[j]);
    rev(v,i+1,j-1);
}

int main(){
    vector<int> v = {1,2,3,5,6};
    int i=0; int j=v.size()-1;

    rev(v,i,j);

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

return 0;
}
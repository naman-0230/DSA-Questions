#include<iostream>
#include<vector>
using namespace std;


int sumArray(vector<int> &v){
    int sumArray = 0;
    for(int i=0; i<v.size(); i++){
    sumArray += v[i];
    }
    return sumArray;
}




int main(){
vector<int>v = {25,46,28,49,24};
int students = 4;
cout<< sumArray(v);

return 0;
}
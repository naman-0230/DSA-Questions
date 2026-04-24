#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    vector<int> v={2,4,3,1,6,7,8,9,0,-2,2};
 int target = 4;
unordered_map<int,int> m;

for(int i=0; i<v.size(); i++){                        //still clearing basics 
    int remaining = target - v[i];

    if(m.find(remaining) != m.end()){
     cout<<remaining<<" "<<v[i]<<endl;
    }
    m[v[i]]=i;

}
return 0;
}
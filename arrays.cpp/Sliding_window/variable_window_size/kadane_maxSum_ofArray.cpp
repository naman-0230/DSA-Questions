#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
 vector<int> v ={2,-3,5,-1,2,-4,-2,3,4,-2};

int current_sum= 0; int max_sum = INT_MIN;
for(int i=0; i< v.size(); i++){
    current_sum += v[i];
    max_sum = max(current_sum, max_sum);

    if(current_sum<0){
        current_sum = 0;
    }

}

cout<< max_sum;

return 0;
}
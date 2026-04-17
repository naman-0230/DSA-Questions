#include<iostream>
#include<vector>
#include<climits>
#include<numeric>        //new one 
using namespace std;

int main(){
 vector<int> v ={3,8,5,1,2,4,5,3,7,8,2,3,1};
int k = 4;

int minsum = INT_MAX; int index;
int sum = 0;

for(int i=0; i< v.size()-k; i++){        //for first n-k elements
   sum += v[i];
}
 minsum = sum;
for(int i = v.size()-k ; i< v.size(); i++){
   sum -= v[i- (v.size()-k)] ;
   sum += v[i];
   minsum = min(minsum , sum);
}

int total = accumulate(v.begin(), v.end(), 0);     //0 is starting sum

//our required max points is total - minsum

int max_points = total - minsum;

cout<< max_points;

return 0;
}
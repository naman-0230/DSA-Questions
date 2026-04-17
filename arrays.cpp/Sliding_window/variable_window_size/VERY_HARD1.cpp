#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<climits>
using namespace std;

int main(){
    vector<int> v = {1,-3,2,-1,2,4,-2,3,4,-2};
    int n = v.size();

    unordered_map<int,int> last;
    vector<long long> prefix(n+1, 0);

    // build prefix sum
    for(int i = 0; i < n; i++){
        prefix[i+1] = prefix[i] + v[i];
    }

    int l = 0;
    long long max_sum = LLONG_MIN;

    multiset<long long> ms;
    ms.insert(prefix[0]);   // initial prefix

    for(int r = 0; r < n; r++){

        // handle duplicate
        if(last.count(v[r])){
            int new_l = last[v[r]] + 1;

            // remove prefix values that are out of range
            while(l < new_l){
                ms.erase(ms.find(prefix[l]));
                l++;
            }
        }

        // compute best sum using smallest prefix
        long long curr_sum = prefix[r+1] - *ms.begin();
        max_sum = max(max_sum, curr_sum);

        // add current prefix
        ms.insert(prefix[r+1]);

        // update last occurrence
        last[v[r]] = r;
    }

    cout << max_sum;
    return 0;
}
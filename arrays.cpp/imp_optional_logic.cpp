#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<optional>   // ✅ added  /// need to update gcc compiler
using namespace std;

class findK{
public: 

    int k;
    findK(int k){
        this->k = k;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    void addnum(int num){
        pq.push(num);
    
        if(pq.size() > k){
            pq.pop();
        }
    }

    optional<int> kfinder(){   // ✅ changed return type
        if(pq.size() < k){
            return nullopt;    // ❌ no fake -1
        }
        else{
            return pq.top();
        }
    }
};

int main (){
    findK kl(3);

    kl.addnum(6);
    kl.addnum(2);

    auto ans1 = kl.kfinder();
    if(ans1) cout << *ans1 << endl;
    else cout << "Not enough elements\n";

    kl.addnum(6);
    kl.addnum(1);
    kl.addnum(10);

    auto ans2 = kl.kfinder();
    if(ans2) cout << *ans2 << endl;
    else cout << "Not enough elements\n";

    kl.addnum(0);

    auto ans3 = kl.kfinder();
    if(ans3) cout << *ans3;
    else cout << "Not enough elements";

    return 0;
}
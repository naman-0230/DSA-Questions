#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

class medianFinder{
    public: 
    
    priority_queue<int, vector<int>, greater<int>> minh;
    priority_queue<int> maxh;

    void addnum(int num){
    //push it into maxh first  
     maxh.push(num);
    //then push its top into right one thats how sorting will be done
    minh.push(maxh.top());
    maxh.pop();
   /// imp order maintaining
    if(minh.size()>maxh.size()){
        maxh.push(minh.top());
        minh.pop();
    }
    // if((maxh.size() - minh.size()) > 1){      not needed if you think clearly
    //   minh.push(maxh.top());
    //   maxh.pop();
    // }
}
    double findMedian(){
      if(maxh.size() > minh.size()){
        return maxh.top();
      }
      else{
        return (maxh.top()+minh.top())/2.0;
      }
    }

};

int main(){
medianFinder mf;
mf.addnum(4);
mf.addnum(3);
mf.addnum(5);

cout<<mf.findMedian()<<endl;
mf.addnum(6);
mf.addnum(8);
mf.addnum(8);
cout<<mf.findMedian();
return 0;
}

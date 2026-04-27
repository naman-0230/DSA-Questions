#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

void insertLast(stack<int> &st, int ele){

    if(st.empty()){
        st.push(ele);
    }
    else{
    int top = st.top();
    st.pop();
    insertLast(st,ele);
    st.push(top);
    }
}

void reverseStack(stack<int> &st){
   if(st.size()==1){
     return;
   }
   else{
    int top = st.top();
    st.pop();
    reverseStack(st);
    insertLast(st, top);
   }
}


int main(){
stack<int> st;
st.push(1);
st.push(2);
st.push(3);
st.push(4);
st.push(5);

reverseStack(st);

while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
}
return 0;
}
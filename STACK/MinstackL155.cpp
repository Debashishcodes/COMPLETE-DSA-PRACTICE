#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<long long> st;
    long long minVal;

    void push(int val) {

        if(st.empty()){
            st.push(val);
            minVal = val;
        }
        else if(val >= minVal){
            st.push(val);
        }
        else{
            st.push(2LL*val - minVal);
            minVal = val;
        }
    }

    void pop() {

        if(st.top() >= minVal){
            st.pop();
        }
        else{
            minVal = 2LL*minVal - st.top();
            st.pop();
        }

    }

    int top() {

        if(st.top() >= minVal){
            return st.top();
        }
        else{
            return minVal;
        }

    }

    int getMin() {
        return minVal;
    }
};

int main(){

    MinStack s;

    s.push(5);
    s.push(3);
    s.push(7);

    cout<<"Top: "<<s.top()<<endl;
    cout<<"Min: "<<s.getMin()<<endl;

    s.pop();

    cout<<"Top after pop: "<<s.top()<<endl;
    cout<<"Min: "<<s.getMin()<<endl;

}
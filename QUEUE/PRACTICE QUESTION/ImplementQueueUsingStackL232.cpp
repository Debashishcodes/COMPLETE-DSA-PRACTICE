// THIS QUESTION CAN BE SOLVE USINNG 2 METHOD
// METHOD -1 ( PUSH EFFICIENT ) T.C = PUSH(O(1)) & POP (O(N))  Under the code below is Push Efficinet
// METHOD -2 ( POP EFFICIENT ) T.C = PUSH(O(N)) & POP (O(1)) 
#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
public:
    stack<int> st;
    stack<int> helper;

    MyQueue() {}

    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        if (st.empty()) return -1;

        while (st.size() > 0) {
            helper.push(st.top());
            st.pop();
        }

        int x = helper.top();
        helper.pop();

        while (helper.size() > 0) {
            st.push(helper.top());
            helper.pop();
        }

        return x;
    }
    
    int peek() {
        if (st.empty()) return -1;

        while (st.size() > 0) {
            helper.push(st.top());
            st.pop();
        }

        int x = helper.top();

        while (helper.size() > 0) {
            st.push(helper.top());
            helper.pop();
        }

        return x;
    }
    
    bool empty() {
        return st.size() == 0;
    }
};

int main() {
    MyQueue q;

    cout << "Push operations:\n";
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "\nPeek (Front): " << q.peek() << endl;

    cout << "\nPop operation: " << q.pop() << endl;

    cout << "Peek after pop: " << q.peek() << endl;

    cout << "\nIs Empty: " << q.empty() << endl;

    cout << "\nPop all elements:\n";
    cout << q.pop() << endl;
    cout << q.pop() << endl;

    cout << "Is Empty now: " << q.empty() << endl;

    return 0;
}
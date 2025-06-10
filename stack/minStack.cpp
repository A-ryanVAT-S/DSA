#include <bits/stdc++.h>
using namespace std;

// min stack is special stack that supports push, pop, top and getMin operations in O(1) time complexity.
// It uses a stack to store the elements and a variable to keep track of the minimum element.

class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val >= mini) {
                st.push(val);
            } else {
                st.push(2LL * val - mini); 
                mini = val;
            }
        }
    }

    void pop() {
        if (st.empty()) return;
        long long top = st.top();
        st.pop();

        if (top < mini) {
            mini = 2LL * mini - top; 
        }
    }

    int top() {
        if (st.empty()) return -1;
        long long top = st.top();
        if (top >= mini) return top;
        else return mini; 
    }

    int getMin() {
        if (st.empty()) return -1;
        return mini;
    }
};

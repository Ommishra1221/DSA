#include<bits/stdc++.h>
using namespace std;

/*
    Function: insertAtBottom
    ------------------------
    Inserts an element at the bottom of the stack
    using recursion.
*/

void insertAtBottom(stack<int>& st, int temp) {

    // Base case: If stack empty → push element
    if(st.empty()) {
        st.push(temp);
        return;
    }

    // Store top element
    int val = st.top();
    st.pop();

    // Recursive call
    insertAtBottom(st, temp);

    // Push stored element back
    st.push(val);
}

/*
    Function: ReverseStack
    ----------------------
    Reverses stack using recursion.

    Logic:
    - Remove top element
    - Reverse remaining stack
    - Insert removed element at bottom
*/

void ReverseStack(stack<int>& st) {

    // Base condition
    if(st.empty()) {
        return;
    }

    // Remove top element
    int temp = st.top();
    st.pop();

    // Reverse remaining stack
    ReverseStack(st);

    // Insert removed element at bottom
    insertAtBottom(st, temp);
}

int main() {

    stack<int> st;

    st.push(5);
    st.push(8);
    st.push(6);
    st.push(0);
    st.push(1);
    st.push(4);
    
    // Reverse stack
    ReverseStack(st);

    // Print reversed stack
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
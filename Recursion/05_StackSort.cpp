#include <bits/stdc++.h>
using namespace std;

/*
    Function: insert
    ----------------
    Inserts an element into the correct position
    in a sorted stack using recursion.

    Logic:
    - If stack is empty OR top element <= temp
        → push temp
    - Otherwise:
        → remove top
        → recursively insert temp
        → push removed element back
*/

void insert(stack<int> &st, int temp) {

    // Base condition:
    // If stack is empty OR correct position found
    if(st.empty() || st.top() <= temp) {
        st.push(temp);
        return;
    }

    // Store top element
    int val = st.top();
    st.pop();

    // Recursive call to insert temp
    insert(st, temp);

    // Push removed element back
    st.push(val);
}


/*
    Function: sortStack
    -------------------
    Recursively sorts the stack.

    Logic:
    - Remove top element
    - Recursively sort remaining stack
    - Insert removed element in correct position
*/

void sortStack(stack<int> &st) {

    // Base condition:
    if(st.empty()) {
        return;
    }

    // Remove top element
    int temp = st.top();
    st.pop();

    // Recursively sort remaining stack
    sortStack(st);

    // Insert removed element correctly
    insert(st, temp);
}


int main() {

    stack<int> st;

    // Pushing elements (unsorted)
    st.push(5);
    st.push(8);
    st.push(6);
    st.push(0);
    st.push(1);

    // Sort the stack
    sortStack(st);

    // Print sorted stack (top to bottom)
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
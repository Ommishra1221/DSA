#include<bits/stdc++.h>
using namespace std;

/*
    Function: DeleteMidStack
    ------------------------
    Deletes the k-th element from top of stack using recursion.

    Logic:
    - If k == 1 → remove the top element (middle)
    - Otherwise:
        - Store top element
        - Recursively call for k-1
        - Push stored element back
*/

void DeleteMidStack(stack<int>& st, int k) {

    // Base Condition:
    // If middle element reached → delete it
    if(k == 1) {
        st.pop();
        return;
    }

    // Store top element
    int temp = st.top();
    st.pop();

    // Recursive call to reach middle
    DeleteMidStack(st, k - 1);

    // Push back stored elements
    st.push(temp);
}

int main() {

    stack<int> st;

    // Pushing elements into stack
    st.push(5);
    st.push(8);
    st.push(6);
    st.push(0);
    st.push(1);
    st.push(4);

    /*
        Find middle position:
        For size n,
        middle = (n / 2) + 1
    */
    int k = (st.size() / 2) + 1;

    // Delete middle element
    DeleteMidStack(st, k);

    // Print stack (top to bottom)
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
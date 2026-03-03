#include<bits/stdc++.h>
using namespace std;

/*
    Function: insert
    ----------------
    Inserts an element (temp) into its correct position 
    in a sorted vector using recursion.
    
    Idea:
    - If vector is empty OR last element <= temp
      → directly push temp
    - Otherwise:
      → remove last element
      → recursively insert temp
      → push removed element back
*/

void insert(vector<int>& v, int temp) {
    
    // Base condition:
    // If vector is empty OR correct position found
    if(v.size() == 0 || v[v.size() - 1] <= temp) {
        v.push_back(temp);
        return;
    }

    // Store last element
    int val = v[v.size() - 1];
    
    // Remove last element
    v.pop_back();

    // Recursive call to find correct position
    insert(v, temp);

    // Put the removed element back
    v.push_back(val);
}


/*
    Function: sort
    --------------
    Recursively sorts the vector.

    Idea:
    - Remove last element
    - Recursively sort remaining vector
    - Insert removed element at correct position
*/

void sort(vector<int>& v) {

    // Base condition:
    // If vector is empty → already sorted
    if(v.size() == 0) {
        return;
    }

    // Remove last element
    int temp = v[v.size() - 1];
    v.pop_back();

    // Recursively sort remaining elements
    sort(v);

    // Insert removed element at correct position
    insert(v, temp);
}


int main() {

    // Unsorted vector
    vector<int> v = {5, 8, 6, 0, 1};

    // Call recursive sort
    sort(v);

    // Print sorted vector
    for(auto it : v) {
        cout << it << " ";
    }

    return 0;
}
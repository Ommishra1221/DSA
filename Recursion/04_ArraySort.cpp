#include <bits/stdc++.h>
using namespace std;

/*
    Insert element in sorted vector using recursion
*/

void insert(vector<int>& v, int temp) {

    if (v.size() == 0 || v.back() <= temp) {
        v.push_back(temp);
        return;
    }

    int val = v.back();
    v.pop_back();

    insert(v, temp);

    v.push_back(val);
}


/*
    Recursive sort function
*/

void sortVector(vector<int>& v) {

    if (v.size() <= 1)
        return;

    int temp = v.back();
    v.pop_back();

    sortVector(v);

    insert(v, temp);
}


int main() {

    vector<int> v = {5, 8, 6, 0, 1};

    sortVector(v);

    for (int x : v) {
        cout << x << " ";
    }

    return 0;
}
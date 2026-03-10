#include<bits/stdc++.h>
using namespace std;

void Reverse(vector<int>& v, int start, int end){

    // Base condition
    if(start >= end){
        return;
    }

    // Swap first and last
    swap(v[start], v[end]);

    // Recursive call
    Reverse(v, start+1, end-1);
}

int main() {

    vector<int> v = {5, 8, 6, 0, 1};

    Reverse(v, 0, v.size()-1);

    for(auto it : v){
        cout << it << " ";
    }

    return 0;
}

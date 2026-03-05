#include <bits/stdc++.h>
using namespace std;

int kthGrammar(int n, int k)
{
    // Base case
    if(n == 1 && k == 1)
        return 0;

    // Mid point of current row
    int mid = pow(2, n-1) / 2;

    // If k lies in first half
    if(k <= mid)
        return kthGrammar(n-1, k);

    // If k lies in second half
    return !kthGrammar(n-1, k - mid);
}

int main()
{
    int n, k;

    cout << "Enter n and k: ";
    cin >> n >> k;

    cout << "Kth Symbol: " << kthGrammar(n, k);

    return 0;
}

/*
    Problem: K-th Symbol in Grammar

    Pattern:
    Row1: 0
    Row2: 01
    Row3: 0110
    Row4: 01101001

    Rules:
    0 -> 01
    1 -> 10

    Key Observations (from video):

    1. Length of row n = 2^(n-1)

    2. First half of row n is SAME as row (n-1)

    3. Second half of row n is COMPLEMENT of row (n-1)

    4. If k is in first half → answer same as previous row
       If k is in second half → answer = NOT(previous row value)

    Recurrence relation:

        mid = 2^(n-1) / 2

        if k <= mid
            kth(n,k) = kth(n-1,k)

        if k > mid
            kth(n,k) = !kth(n-1,k-mid)

    Base Case:
        n=1 and k=1 → return 0
*/
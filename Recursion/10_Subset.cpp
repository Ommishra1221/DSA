#include <bits/stdc++.h>
using namespace std;

void solve(string inp, string opt, int &count)
{
    // Base Case: input string is empty
    if(inp.length() == 0)
    {
        cout << opt << endl;
        count++;
        return;
    }

    // Option 1: exclude current character
    string op1 = opt;

    // Option 2: include current character
    string op2 = opt;
    op2.push_back(inp[0]);

    // Reduce problem size (remove first character)
    inp.erase(inp.begin());

    // Recursive calls
    solve(inp, op1, count);
    solve(inp, op2, count);
}

int main()
{
    string inp = "abc";
    string out = "";

    int count = 0;

    solve(inp, out, count);

    cout << "\nTotal subsequences: " << count << endl;

    return 0;
}


/*
    Problem: Print all subsequences of a string

    Example:
    Input: "abc"

    Subsequences:
    ""  "a"  "b"  "c"  "ab"  "ac"  "bc"  "abc"

    Total subsequences = 2^n

    Idea (Recursion Tree):
    For every character we have two choices:

    1️⃣ Exclude the character
    2️⃣ Include the character

    So recursion branches into 2 calls.
*/

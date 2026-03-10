#include <bits/stdc++.h>
using namespace std;

void solve(string input, string output)
{
    // Base Case
    if(input.length() == 0)
    {
        cout << output << endl;
        return;
    }

    // Option 1: keep character as it is
    string op1 = output;
    op1.push_back(input[0]);

    // Option 2: convert to uppercase
    string op2 = output;
    op2.push_back(toupper(input[0]));

    // Reduce input
    input.erase(input.begin());

    // Recursive calls
    solve(input, op1);
    solve(input, op2);
}

int main()
{
    string input = "abc";
    string output = "";

    solve(input, output);

    return 0;
}

/*
    Problem: Permutation with Case Change

    Example:
    Input: "abc"

    Output:
    abc
    abC
    aBc
    aBC
    Abc
    AbC
    ABc
    ABC

        ""
       /  \
      a    A
     / \  / \
    ab aB Ab AB
   / / / / / / /
 abc abC aBc aBC Abc AbC ABc ABC
    Idea:
    -----
    For every character we have two choices:

    1️⃣ Keep the character as it is
    2️⃣ Convert it to uppercase

    This creates 2 recursive branches.
*/
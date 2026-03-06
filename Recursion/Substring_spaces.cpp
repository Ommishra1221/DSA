#include <bits/stdc++.h>
using namespace std;

void solve(string input, string output)
{
    // Base Case: when input becomes empty
    if(input.length() == 0)
    {
        cout << output << endl;
        return;
    }

    // Option 1: add space before next character
    string op1 = output;
    op1.push_back(' ');
    op1.push_back(input[0]);

    // Option 2: add character directly
    string op2 = output;
    op2.push_back(input[0]);

    // Reduce input
    input.erase(input.begin());

    // Recursive calls
    solve(input, op1);
    solve(input, op2);
}

int main()
{
    string input = "ABC";

    // First character always appears without space
    string output = "";
    output.push_back(input[0]);

    // Remove first character from input
    input.erase(input.begin());

    // Start recursion
    solve(input, output);

    return 0;
}
/*
    Problem: Permutation with Spaces

    Example:
    Input: ABC

    Output:
    A B C
    A BC
    AB C
    ABC

        A
       / \
     A B  AB
    /  \  / \
 A B C A BC AB C ABC
    Idea:
    -----
    For every character we have two choices:
    
    1️⃣ Add space before the character
    2️⃣ Add character directly

    Recursion Pattern:
    Input - Output method
*/
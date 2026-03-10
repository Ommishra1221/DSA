#include <bits/stdc++.h>
using namespace std;

set<string> result;   // Stores only unique subsets

void solve(string input, string output)
{
    // Base Case
    if(input.length() == 0)
    {
        result.insert(output);
        return;
    }

    // Option 1: Exclude character
    string op1 = output;

    // Option 2: Include character
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
    string input = "aab";
    string output = "";

    solve(input, output);

    cout << "Unique Subsets:\n";

    for(auto it : result)
        cout << it << endl;

    return 0;
}


/*
    Problem: Print Unique Subsets

    Example:
    Input:  aab

    Subsets:
    ""
    a
    aa
    aab
    ab
    b

    Key Idea:
    ----------
    1. For every character we have two choices:
       - Include it
       - Exclude it

    2. If duplicates exist, we must avoid generating
       duplicate subsets.

    3. To handle duplicates:
       Use a SET to store unique results.

    4. Recursion follows Input-Output method.
*/

#include <bits/stdc++.h>
using namespace std;

void solve(string input, string output, vector<string> &v)
{
    // Base Case
    if (input.length() == 0)
    {
        v.push_back(output);
        return;
    }

    // If alphabet
    if (isalpha(input[0]))
    {
        string op1 = output;
        string op2 = output;

        op1.push_back(tolower(input[0]));
        op2.push_back(toupper(input[0]));

        input.erase(input.begin());

        solve(input, op1, v);
        solve(input, op2, v);
    }
    else
    {
        // Digit → only one option
        string op1 = output;
        op1.push_back(input[0]);

        input.erase(input.begin());

        solve(input, op1, v);
    }
}

int main()
{
    string input = "A2b35";
    string output = "";
    vector<string> v;

    solve(input, output, v);

    for (auto it : v)
        cout << it << endl;

    return 0;
}

/*
    Problem: Letter Case Permutation

    Example:
    Input: A2b35

    Output:
    a2b35
    a2B35
    A2b35
    A2B35

    Idea:
    - If character is a letter → two choices
        1. lowercase
        2. uppercase
    - If character is a digit → only one choice
*/
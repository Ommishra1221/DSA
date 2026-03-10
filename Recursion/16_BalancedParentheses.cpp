#include<bits/stdc++.h>
using namespace std;

void solve(string output, int op, int cl)
{
    // Base condition
    if(op == 0 && cl == 0)
    {
        cout << output << endl;
        return;
    }

    // Choice 1 → place '('
    if(op > 0)
    {
        string op1 = output;
        op1.push_back('(');
        solve(op1, op - 1, cl);
    }

    // Choice 2 → place ')'
    if(cl > op)
    {
        string op2 = output;
        op2.push_back(')');
        solve(op2, op, cl - 1);
    }
}

int main()
{
    int n;
    cin >> n;

    int op = n;
    int cl = n;

    string output = "";

    solve(output, op, cl);

    return 0;
}

/*
    Problem: Generate Balanced Parentheses

    Example:
    n = 3

    Output:
    ((()))
    (()())
    (())()
    ()(())
    ()()()

    Idea (Aditya Verma Style):

    op = number of '(' remaining
    cl = number of ')' remaining

    Rules:
    1. If op > 0 → we can place '('
    2. If cl > op → we can place ')'
*/
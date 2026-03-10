#include<bits/stdc++.h>
using namespace std;


void solve(int ones, int zeros, int n, string output)
{
    // Base condition
    if(n == 0)
    {
        cout << output << endl;
        return;
    }

    // Choice 1 → place '1'
    string op1 = output;
    op1.push_back('1');
    solve(ones + 1, zeros, n - 1, op1);
    
    if(ones>zeros){
        string op2=output;
        op2.push_back('0');
        solve(ones,zeros+1,n-1,op2);
    }

}

int main()
{
    int n=4;
    

    int ones = 0;
    int zeros = 0;

    string output = "";

    solve(ones, zeros, n, output);

    return 0;
}

/*
    Problem: Print N-bit binary numbers having more 1’s than 0’s for any prefix

    Example:
    Input:
    n = 3

    Output:
    111
    110
    101

    Idea:
    ones  -> count of 1's placed
    zeros -> count of 0's placed

    Condition:
    zeros <= ones
*/
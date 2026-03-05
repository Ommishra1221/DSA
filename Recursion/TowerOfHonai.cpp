#include <bits/stdc++.h>
using namespace std;

void solve(int n, char source, char helper, char destination, int &count)
{
    // Base Case
    if(n == 1)
    {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        count++;
        return;
    }

    /*
        Step 1:
        Move n-1 disks
        source → helper
    */
    solve(n-1, source, destination, helper, count);

    /*
        Step 2:
        Move nth disk
        source → destination
    */
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    count++;

    /*
        Step 3:
        Move n-1 disks
        helper → destination
    */
    solve(n-1, helper, source, destination, count);
}

int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    int count = 0;

    // A = Source, B = Helper, C = Destination
    solve(n, 'A', 'B', 'C', count);

    cout << "\nTotal moves required: " << count << endl;

    /*
        Mathematical Formula:
        Total Moves = 2^n - 1
    */

    return 0;
}


/*
    Tower of Hanoi (Classic Recursion Problem)

    Mythological Context:
    ---------------------
    According to a legend, Lord Brahma created a temple with
    3 poles and 64 golden disks. Priests must move all disks
    from source to destination following the rules.
    When they finish, the universe will end!

    If n = 64
    Total moves = 2^64 - 1
    That would take more than 585 billion years.

    -------------------------------------------------

    Problem Statement:
    Move n disks from SOURCE pole to DESTINATION pole
    using HELPER pole.

    Rules:
    1. Only one disk can be moved at a time.
    2. A bigger disk cannot be placed on a smaller disk.

    -------------------------------------------------

    Recursive Thinking (IBH Method)

    I → Induction
    B → Base Case
    H → Hypothesis

    Hypothesis:
    Assume we know how to move (n-1) disks.

    Steps:

    Step 1:
    Move top (n-1) disks from SOURCE → HELPER
    using DESTINATION as helper.

    Step 2:
    Move largest disk (nth disk)
    from SOURCE → DESTINATION.

    Step 3:
    Move (n-1) disks from HELPER → DESTINATION
    using SOURCE as helper.

    -------------------------------------------------

    Base Case:
    If n == 1
    simply move disk from SOURCE → DESTINATION
*/

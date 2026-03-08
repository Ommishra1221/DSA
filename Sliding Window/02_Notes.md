🪟 Sliding Window Algorithm (Aditya Verma Style Notes)

A powerful technique used to solve array and string problems involving contiguous subarrays or substrings efficiently.

1️⃣ Pattern Name
Sliding Window Pattern

Used for solving problems involving:

Contiguous subarrays

Contiguous substrings

Maximum / Minimum / Count type problems

2️⃣ Problem Motivation

Many interview problems ask things like:

Maximum sum subarray

Longest substring

Minimum window substring

Count of valid subarrays

A naive solution usually:

Generates every possible subarray

Computes the result for each

This leads to nested loops.

⛔ Brute Force Complexity
O(n²)
✅ Sliding Window Optimization
O(n)
3️⃣ Classic Example Problem
Problem

Find the maximum sum of any subarray of size K.

Example
Input:
arr = [2,5,1,8,2,9,1]
K = 3
Output:
19
Explanation

Subarrays of size 3

[2,5,1] = 8
[5,1,8] = 14
[1,8,2] = 11
[8,2,9] = 19   ← Maximum
[2,9,1] = 12
4️⃣ Brute Force Approach
Idea

Generate all subarrays of size K

Compute sum each time

Time Complexity
O(n * k)
C++ Implementation
#include <bits/stdc++.h>
using namespace std;

int maxSumSubarray(vector<int>& arr, int k)
{
    int n = arr.size();
    int maxSum = INT_MIN;

    for(int i = 0; i <= n - k; i++)
    {
        int currentSum = 0;

        for(int j = i; j < i + k; j++)
        {
            currentSum += arr[j];
        }

        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}
🚨 Problem with Brute Force

Repeated calculations.

Example:

[2,5,1]
[5,1,8]

The elements 5 and 1 are recalculated again.

This wastes time.

5️⃣ Sliding Window Optimization
Core Idea

Instead of recomputing the entire sum:

1️⃣ Remove the element leaving the window
2️⃣ Add the element entering the window

Example
Window 1: [2,5,1] → sum = 8

Next window:

[5,1,8]

Instead of recomputing:

New sum = previous sum - 2 + 8

We reuse previous work.

6️⃣ Sliding Window Algorithm Steps

1️⃣ Maintain a window sum

2️⃣ Expand window using right pointer

3️⃣ When window size reaches K

Update answer

4️⃣ Slide the window forward

7️⃣ Optimized C++ Implementation
#include <bits/stdc++.h>
using namespace std;

int maxSumSubarray(vector<int>& arr, int k)
{
    int n = arr.size();

    int windowSum = 0;
    int maxSum = INT_MIN;

    int left = 0;

    for(int right = 0; right < n; right++)
    {
        windowSum += arr[right];

        if(right - left + 1 == k)
        {
            maxSum = max(maxSum, windowSum);

            windowSum -= arr[left];
            left++;
        }
    }

    return maxSum;
}
8️⃣ Time Complexity
O(n)

Each element is visited at most twice.

9️⃣ Space Complexity
O(1)

Only a few variables are used.

🔟 Types of Sliding Window Problems

Sliding window problems are mainly two types.

1️⃣ Fixed Size Window

The window size K is given.

Example Problems:

Maximum Sum Subarray of Size K

First Negative Number in Window

Count Occurrences of Anagrams

Maximum Element in Every Window

Structure
for(int right = 0; right < n; right++)
{
    windowSum += arr[right];

    if(windowSize < k)
        expand window

    if(windowSize == k)
    {
        calculate answer

        slide window
    }
}
2️⃣ Variable Size Window

Window size is NOT fixed.

Window expands until a condition is satisfied
Then it shrinks.

Example Problems

Longest substring without repeating characters

Minimum window substring

Longest substring with K unique characters

Structure
while(right < n)
{
    expand window

    if(condition < required)
        expand window

    else if(condition == required)
        update answer

    else if(condition > required)
        shrink window
}
1️⃣1️⃣ How to Identify Sliding Window Problems

Sliding Window is applicable when:

✔ Problem involves arrays or strings

✔ Question involves subarray or substring

✔ Need maximum / minimum / count

✔ Only contiguous elements

Common Keywords
largest
smallest
maximum
minimum
substring
subarray
window
1️⃣2️⃣ Why Sliding Window is Powerful
Brute Force
O(n²)
Sliding Window
O(n)

Huge performance improvement for large inputs.

1️⃣3️⃣ Sliding Window Templates (Important)
Fixed Window Template
int left = 0;

for(int right = 0; right < n; right++)
{
    window_operation

    if(right - left + 1 == k)
    {
        update answer

        remove arr[left]

        left++
    }
}
Variable Window Template
int left = 0;

for(int right = 0; right < n; right++)
{
    expand window

    while(condition not satisfied)
    {
        shrink window
        left++
    }

    update answer
}
1️⃣4️⃣ Quick Revision

Sliding Window reduces:

O(n²) → O(n)

Two types:

1️⃣ Fixed Window
2️⃣ Variable Window

Core Idea
Add next element
Remove previous element
Use Sliding Window When Problem Has

Subarray

Substring

Contiguous elements

💡 Interview Tip

Sliding Window is often combined with:

HashMap

Set

Deque

Frequency Array

Especially in Variable Size Window problems.
Sliding Window Algorithm (Aditya Verma Style Notes)
Pattern Name

Sliding Window Pattern

Used for solving array and string problems involving contiguous subarrays or substrings.

1. Problem Motivation

Many interview problems ask things like:

Maximum sum subarray

Longest substring

Minimum window substring

Count of valid subarrays

A brute force solution often looks like:

Generate every subarray
Calculate something for each subarray

This leads to nested loops.

Time Complexity:

O(n²)

Sliding Window reduces this to:

O(n)
2. Classic Example Problem
Problem

Find the maximum sum of any subarray of size K.

Example
Input:
arr = [2,5,1,8,2,9,1]
K = 3

Output:
19

Explanation:

Subarrays of size 3

[2,5,1] = 8
[5,1,8] = 14
[1,8,2] = 11
[8,2,9] = 19  ← maximum
[2,9,1] = 12
3. Brute Force Approach
Idea

Generate all subarrays of size K and compute sum each time.

Time Complexity
O(n*k)
Code
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

Problem: Repeated calculations

Example:

[2,5,1]
[5,1,8]

The elements 5 and 1 are recalculated again.

4. Sliding Window Optimization
Core Idea

Instead of recomputing the sum:

Remove the element leaving the window
Add the element entering the window

Example:

Window 1: [2,5,1] sum = 8
Window 2: [5,1,8]

New sum = previous sum - 2 + 8

So we reuse previous work.

5. Sliding Window Algorithm Steps

Maintain a window sum

Expand window using right pointer

When window size reaches K

Update answer

Slide the window forward

6. Optimized C++ Implementation
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
7. Time Complexity
O(n)

Each element is visited at most twice.

8. Space Complexity
O(1)

Only a few variables are used.

9. Types of Sliding Window Problems

Sliding Window problems are mainly two types.

9.1 Fixed Size Window

Window size K is given.

Example Problems:

Maximum Sum Subarray of size K

First Negative Number in Window

Count occurrences of anagrams

Maximum in every window

Structure:

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
9.2 Variable Size Window

Window size is not fixed.

Window expands until a condition is satisfied.

Then shrinks.

Example Problems:

Longest substring without repeating characters

Minimum window substring

Longest substring with K unique characters

Structure:

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
10. How to Identify Sliding Window Problems

Sliding window is applicable when:

Problem involves arrays or strings

Question involves subarray or substring

Need maximum / minimum / count

Contiguous elements only

Common keywords:

largest
smallest
maximum
minimum
substring
subarray
window
11. Why Sliding Window is Powerful

Brute Force:

O(n²)

Sliding Window:

O(n)

This drastically improves performance for large inputs.

12. Sliding Window Template (Important)
Fixed Window Template
int left = 0;

for(int right = 0; right < n; right++)
{
    window_operation

    if(right - left + 1 == k)
    {
        answer update

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
13. Revision Notes (Quick)

Sliding Window reduces

O(n²) → O(n)

Two types:

1. Fixed Window
2. Variable Window

Key Idea:

Add next element
Remove previous element

Use when problem involves:

subarray
substring
contiguous elements
14. Interview Tip

Sliding window often combines with:

HashMap
Set
Deque
Frequency array

Especially in variable size window problems.
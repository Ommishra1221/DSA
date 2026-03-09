#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    
    vector<int> firstNegInt(vector<int>& arr, int k) {

        vector<int> ans;      // stores final answer
        queue<int> q;         // queue to store negative numbers

        int i = 0;
        int j = 0;
        int n = arr.size();

        while (j < n) {

            // If current element is negative, store it
            if (arr[j] < 0) {
                q.push(arr[j]);
            }

            // Window size smaller than k → expand
            if (j - i + 1 < k) {
                j++;
            }

            // Window size reached k
            else if (j - i + 1 == k) {

                // Check first negative number
                if (!q.empty())
                    ans.push_back(q.front());
                else
                    ans.push_back(0);

                // Remove element leaving window
                if (!q.empty() && arr[i] == q.front()) {
                    q.pop();
                }

                // Slide window
                i++;
                j++;
            }
        }

        return ans;
    }
};


int main() {

    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    Solution obj;

    vector<int> result = obj.firstNegInt(arr, k);

    cout << "First negative number in every window: ";

    for (int num : result) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}


/*
===============================================================
Notes (For GitHub / Revision)

Key Idea:
Instead of scanning every window again,
store useful elements (negative numbers) in a queue.

Queue Front → Always first negative in window.

Pattern Type:
Fixed Size Sliding Window

Common Similar Problems:
1. Maximum sum subarray of size K
2. Maximum element in every window
3. Count occurrences of anagrams
4. First negative number in window

This pattern reduces time complexity
from O(n*k) → O(n).

Author: Om Mishra
===============================================================
*/
/*
===============================================================
Problem: First Negative Integer in Every Window of Size K
Pattern: Sliding Window (Fixed Size)

Description:
Given an array of integers and a window size K,
find the first negative integer in every window of size K.

If a window does not contain a negative number,
return 0 for that window.

Example:
Input:
arr = [12, -1, -7, 8, -15, 30, 16, 28]
k = 3

Windows:
[12, -1, -7]   -> -1
[-1, -7, 8]    -> -1
[-7, 8, -15]   -> -7
[8, -15, 30]   -> -15
[-15, 30, 16]  -> -15
[30, 16, 28]   -> 0

Output:
[-1, -1, -7, -15, -15, 0]

---------------------------------------------------------------
Approach: Sliding Window

We maintain a queue that stores negative numbers
present in the current window.

Steps:
1. Expand window using pointer j
2. If arr[j] is negative → push it to queue
3. When window size becomes k:
      - queue.front() = first negative number
      - if queue empty → answer = 0
4. Before sliding window:
      if arr[i] equals queue.front()
      remove it from queue
5. Slide window forward

---------------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(k)
===============================================================
*/
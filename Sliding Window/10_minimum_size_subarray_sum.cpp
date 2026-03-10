
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int i = 0, j = 0;
        int sum = 0;
        int minLen = INT_MAX;

        while (j < nums.size()) {

            // Expand window
            sum += nums[j];

            // Shrink window when condition is satisfied
            while (sum >= target) {
                minLen = min(minLen, j - i + 1);
                sum -= nums[i];
                i++;
            }

            j++;
        }

        if (minLen == INT_MAX)
            return 0;

        return minLen;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;

    int result = obj.minSubArrayLen(target, nums);

    cout << "Minimum length subarray: " << result << endl;

    return 0;
}
/*
===============================================================
Problem: Minimum Size Subarray Sum
LeetCode: 209

Description:
Given an array of positive integers nums and a positive integer
target, return the minimal length of a subarray whose sum is
greater than or equal to target.

If no such subarray exists, return 0.

Example:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2

Explanation:
The subarray [4,3] has the minimal length under the constraint.

---------------------------------------------------------------
Pattern Used:
Sliding Window (Variable Size Window)

Key Idea:
1. Expand the window by increasing j.
2. Add nums[j] to the running sum.
3. When sum >= target, shrink the window from the left (i++)
   to find the minimum length.
4. Update the minimum length during shrinking.

Time Complexity: O(n)
Space Complexity: O(1)
===============================================================
*/

/*
===============================================================
Sliding Window Insight

For Minimum Window Problems:
Expand window → j++
When condition satisfied → shrink window → i++

Important:
Always update the answer while shrinking the window.

===============================================================
*/
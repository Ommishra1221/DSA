#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {

        int sum = 0;
        int maxsum = INT_MIN;

        int i = 0;
        int j = 0;
        int n = arr.size();

        // Sliding Window
        while (j < n) {

            sum += arr[j];

            // Window size < k
            if (j - i + 1 < k) {
                j++;
            }

            // Window size == k
            else if (j - i + 1 == k) {

                maxsum = max(maxsum, sum);

                // Remove element leaving the window
                sum = sum - arr[i];

                // Slide the window
                i++;
                j++;
            }
        }

        return maxsum;
    }
};

int main() {

    Solution obj;

    vector<int> arr = {2, 5, 1, 8, 2, 9, 1};
    int k = 3;

    int result = obj.maxSubarraySum(arr, k);

    cout << "Maximum Sum of Subarray of Size k: " << result << endl;

    return 0;
}


/*
============================================================
PROBLEM: Maximum Sum Subarray of Size K
============================================================

Given:
- An integer array arr[]
- An integer k

Find the maximum sum of any contiguous subarray of size k.

------------------------------------------------------------
Example
------------------------------------------------------------

arr = [2, 5, 1, 8, 2, 9, 1]
k = 3

Possible subarrays of size 3:

[2, 5, 1] -> sum = 8
[5, 1, 8] -> sum = 14
[1, 8, 2] -> sum = 11
[8, 2, 9] -> sum = 19   <-- maximum
[2, 9, 1] -> sum = 12

Answer = 19

------------------------------------------------------------
OPTIMAL APPROACH (Sliding Window)
------------------------------------------------------------

Instead of calculating the sum of every subarray again and again,
we maintain a window of size k.

Steps:

1. Expand window by adding arr[j]
2. When window size becomes k:
       update the maximum sum
3. Before sliding the window forward:
       remove arr[i]
4. Move both pointers


------------------------------------------------------------
Sliding Window Visualization
------------------------------------------------------------

arr = [2,5,1,8,2,9,1]
k = 3

Step 1
[2 5 1] 8 2 9 1
sum = 8

Step 2
2 [5 1 8] 2 9 1
sum = 14

Step 3
2 5 [1 8 2] 9 1
sum = 11

Step 4
2 5 1 [8 2 9] 1
sum = 19  <-- maximum


------------------------------------------------------------
Time Complexity
------------------------------------------------------------

O(N)

Each element is added and removed once.

------------------------------------------------------------
Space Complexity
------------------------------------------------------------

O(1)

No extra data structures are used.


------------------------------------------------------------
Key Concept
------------------------------------------------------------

This problem follows the pattern:

"Fixed Size Sliding Window"

Whenever a problem asks:

- subarray of size k
- maximum sum
- minimum sum
- average of k elements

Think of Sliding Window.

============================================================
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {

        int i = 0;
        int j = 0;
        int n = nums.size();

        int sum = 0;
        int maxsum = INT_MIN;

        // Sliding Window
        while (j < n)
        {

            sum = sum + nums[j];

            // Window size < k
            if (j - i + 1 < k)
            {
                j++;
            }

            // Window size == k
            else if (j - i + 1 == k)
            {

                maxsum = max(maxsum, sum);

                // Remove the element leaving the window
                sum = sum - nums[i];

                // Slide the window
                i++;
                j++;
            }
        }

        return (double)maxsum / k;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    double result = obj.findMaxAverage(nums, k);

    cout << "Maximum Average Subarray: " << result << endl;

    return 0;
}

/*
===========================================================
PROBLEM: Maximum Average Subarray I
===========================================================

We are given:
- An integer array nums
- An integer k

We need to find the maximum average of any contiguous
subarray of size k.

-----------------------------------------------------------
Example
-----------------------------------------------------------

nums = [1, 12, -5, -6, 50, 3]
k = 4

Possible windows of size 4:

[1, 12, -5, -6]  -> sum = 2
[12, -5, -6, 50] -> sum = 51
[-5, -6, 50, 3]  -> sum = 42

Maximum sum = 51

Average = 51 / 4 = 12.75


-----------------------------------------------------------
OPTIMAL APPROACH (Sliding Window)
-----------------------------------------------------------

Instead of recalculating the sum of every subarray,
we maintain a window of size k.

Steps:

1. Expand the window by adding nums[j]
2. When window size becomes k:
       update the maximum sum
3. Before sliding the window:
       remove nums[i]
4. Move the window forward


-----------------------------------------------------------
Sliding Window Visualization
-----------------------------------------------------------

nums = [1, 12, -5, -6, 50, 3]
k = 4

Step 1
[1 12 -5 -6] 50 3
sum = 2

Step 2
1 [12 -5 -6 50] 3
sum = 51  (maximum)

Step 3
1 12 [-5 -6 50 3]
sum = 42


-----------------------------------------------------------
Time Complexity
-----------------------------------------------------------

O(N)

Each element enters and leaves the window once.


-----------------------------------------------------------
Space Complexity
-----------------------------------------------------------

O(1)

No extra data structures used.


-----------------------------------------------------------
Important Concept
-----------------------------------------------------------

This problem uses the

"Fixed Size Sliding Window"

pattern.

Whenever the problem says:

- subarray of size k
- maximum sum
- minimum sum
- average of k elements

Think immediately of Sliding Window.

===========================================================
*/
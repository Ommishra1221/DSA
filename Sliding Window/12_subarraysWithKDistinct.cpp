#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int atMostK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int i = 0, j = 0;
        int count = 0;

        while (j < nums.size()) {

            mp[nums[j]]++;

            while (mp.size() > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }

            count += j - i + 1;
            j++;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1,2,1,2,3};
    int k = 2;

    cout << "Subarrays with exactly K distinct: "
         << obj.subarraysWithKDistinct(nums, k) << endl;

    return 0;
}

/*
===============================================================
Problem: 992. Subarrays with K Different Integers
LeetCode: https://leetcode.com/problems/subarrays-with-k-different-integers/

Description:
Return the number of subarrays that contain exactly K distinct integers.

Key Idea:
exactly(K) = atMost(K) - atMost(K-1)

Pattern Used:
Sliding Window (Variable Size Window)

Time Complexity: O(n)
Space Complexity: O(n)
===============================================================
*/
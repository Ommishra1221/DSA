#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int i = 0, j = 0;
        int k = 2;
        int maxlen = 0;

        unordered_map<int, int> mp;

        while (j < fruits.size()) {

            // Add current fruit to window
            mp[fruits[j]]++;

            // Case 1: Less than k distinct fruits
            if (mp.size() < k) {
                j++;
            }

            // Case 2: Exactly k distinct fruits
            else if (mp.size() == k) {
                maxlen = max(maxlen, j - i + 1);
                j++;
            }

            // Case 3: More than k distinct fruits → shrink window
            else if (mp.size() > k) {

                while (mp.size() > k) {
                    mp[fruits[i]]--;

                    if (mp[fruits[i]] == 0) {
                        mp.erase(fruits[i]);
                    }

                    i++;
                }

                j++;
            }
        }

        return maxlen;
    }
};

int main() {

    Solution obj;

    vector<int> fruits = {1,2,3,2,2};

    cout << "Maximum fruits in two baskets: "
         << obj.totalFruit(fruits) << endl;

    return 0;
}

/*
===============================================================
Problem: Fruit Into Baskets
LeetCode: 904

Description:
You are given an array 'fruits' where fruits[i] represents the
type of fruit on the ith tree.

You have two baskets and each basket can only hold one type of
fruit, but unlimited quantity.

Return the length of the longest subarray that contains
at most 2 distinct fruits.

Example:
Input:  fruits = [1,2,1]
Output: 3

Input:  fruits = [0,1,2,2]
Output: 3

Pattern Used:
Sliding Window (Variable Size Window)

Time Complexity: O(n)
Space Complexity: O(1)  (at most 3 keys in map)
===============================================================
*/
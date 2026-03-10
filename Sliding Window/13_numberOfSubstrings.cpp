#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {

        int i = 0, j = 0;
        int cnt = 0;
        int n = s.length();

        unordered_map<char,int> mp;

        while (j < n) {

            mp[s[j]]++;

            // If window contains all three characters
            while (mp.size() == 3) {

                cnt += (n - j);

                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);

                i++;
            }

            j++;
        }

        return cnt;
    }
};

int main() {

    Solution obj;
    string s = "abcabc";

    cout << "Number of valid substrings: "
         << obj.numberOfSubstrings(s) << endl;

    return 0;
}

/*
===========================================================
Problem: 1358. Number of Substrings Containing All Three Characters
Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

Description:
Given a string consisting only of characters 'a', 'b', and 'c',
return the number of substrings containing at least one of each character.

Approach:
Sliding Window (Variable Size Window)

Key Idea:
When the window contains all three characters,
all substrings starting at i and ending at j..n-1 are valid.

Time Complexity: O(n)
Space Complexity: O(1)
===========================================================
*/
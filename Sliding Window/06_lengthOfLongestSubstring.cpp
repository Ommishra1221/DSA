#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int> mp;

        int i = 0;
        int j = 0;

        int ans = 0;

        // Sliding Window
        while (j < s.size()) {

            // Include current character in window
            mp[s[j]]++;

            // Case 1: All characters are unique
            if (mp.size() == j - i + 1) {
                ans = max(ans, j - i + 1);
                j++;
            }

            // Case 2: Duplicate characters exist
            else if (mp.size() < j - i + 1) {

                while (mp.size() < j - i + 1) {

                    mp[s[i]]--;

                    if (mp[s[i]] == 0) {
                        mp.erase(s[i]);
                    }

                    i++;
                }

                j++;
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string s = "abcabcbb";

    int result = obj.lengthOfLongestSubstring(s);

    cout << "Length of Longest Substring Without Repeating Characters: "
         << result << endl;

    return 0;
}


/*
====================================================================
PROBLEM: Longest Substring Without Repeating Characters
====================================================================

Given a string s, find the length of the longest substring
that contains no repeating characters.

--------------------------------------------------------------------
Example
--------------------------------------------------------------------

Input:
s = "abcabcbb"

Substrings:

"abc" → length = 3
"bca" → length = 3
"cab" → length = 3

Longest substring without repeating characters = 3


Another Example:

s = "bbbbb"

Possible substring without repeating characters:

"b" → length = 1


--------------------------------------------------------------------
OPTIMAL APPROACH (Variable Size Sliding Window)
--------------------------------------------------------------------

We use two pointers:

i → start of window
j → end of window

We also maintain a hashmap to track frequency of characters.

Steps:

1. Expand window by including s[j]
2. Store frequency in hashmap
3. If all characters are unique
       update answer
4. If duplicate appears
       shrink window from left
       until duplicates are removed


--------------------------------------------------------------------
Sliding Window Visualization
--------------------------------------------------------------------

s = "abcabcbb"

Step 1
[a b c] a b c b b
All unique → length = 3

Step 2
a [b c a] b c b b
duplicate 'a' appears

Shrink window until duplicate removed


--------------------------------------------------------------------
Key Idea
--------------------------------------------------------------------

If:

map.size() == window size

→ all characters are unique


--------------------------------------------------------------------
Time Complexity
--------------------------------------------------------------------

O(N)

Each character is visited at most twice.


--------------------------------------------------------------------
Space Complexity
--------------------------------------------------------------------

O(K)

Where K = number of unique characters.

--------------------------------------------------------------------
Pattern Used
--------------------------------------------------------------------

Variable Size Sliding Window


Whenever a problem asks:

- Longest substring
- No repeating characters
- At most K unique characters

Think immediately of

"Variable Sliding Window"

====================================================================
*/
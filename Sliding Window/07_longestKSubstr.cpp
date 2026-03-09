#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int longestKSubstr(string &s, int k) {

        int i = 0;
        int j = 0;
        int ans = -1;

        unordered_map<char,int> mpp;

        // Variable Size Sliding Window
        while (j < s.length()) {

            // Include current character in window
            mpp[s[j]]++;

            // Case 1: Number of unique characters < k
            if (mpp.size() < k) {
                j++;
            }

            // Case 2: Exactly k unique characters
            else if (mpp.size() == k) {
                ans = max(ans, j - i + 1);
                j++;
            }

            // Case 3: More than k unique characters
            else if (mpp.size() > k) {

                while (mpp.size() > k) {

                    mpp[s[i]]--;

                    if (mpp[s[i]] == 0) {
                        mpp.erase(s[i]);
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

    string s = "aabacbebebe";
    int k = 3;

    int result = obj.longestKSubstr(s, k);

    cout << "Length of Longest Substring with K Unique Characters: "
         << result << endl;

    return 0;
}


/*
====================================================================
PROBLEM: Longest Substring with Exactly K Unique Characters
====================================================================

Given:
- A string s
- An integer k

Find the length of the longest substring that contains
exactly k unique characters.

If such substring does not exist, return -1.

--------------------------------------------------------------------
Example
--------------------------------------------------------------------

Input:
s = "aabacbebebe"
k = 3

Possible substrings with exactly 3 unique characters:

"aabac"
"cbebebe"

Longest = "cbebebe"

Length = 7


--------------------------------------------------------------------
OPTIMAL APPROACH (Variable Size Sliding Window)
--------------------------------------------------------------------

We use two pointers:

i → start of window
j → end of window

We maintain a hashmap to count character frequencies.

Steps:

1. Expand the window by including s[j]
2. Store frequency in hashmap
3. If number of unique characters < k
       expand window (move j)
4. If number of unique characters == k
       update answer
5. If number of unique characters > k
       shrink window from left
       until unique characters become k


--------------------------------------------------------------------
Sliding Window Visualization
--------------------------------------------------------------------

s = "aabacbebebe"
k = 3

[a a b a c] b e b e b e
unique = 3 → valid

Shrink and expand window to maintain exactly k unique characters.


--------------------------------------------------------------------
Key Observation
--------------------------------------------------------------------

We track:

mpp.size() → number of unique characters in window

Cases:

mpp.size() < k   → expand window
mpp.size() == k  → update answer
mpp.size() > k   → shrink window


--------------------------------------------------------------------
Time Complexity
--------------------------------------------------------------------

O(N)

Each character is visited at most twice.


--------------------------------------------------------------------
Space Complexity
--------------------------------------------------------------------

O(K)

For storing unique characters in the hashmap.


--------------------------------------------------------------------
Pattern Used
--------------------------------------------------------------------

Variable Size Sliding Window


Whenever the problem asks:

- Longest substring
- Exactly K unique characters
- At most K unique characters

Think of

"Variable Size Sliding Window"

====================================================================
*/
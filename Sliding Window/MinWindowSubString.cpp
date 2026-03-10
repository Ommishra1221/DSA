#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> mp;

        // store frequency of pattern
        for(char c : t){
            mp[c]++;
        }

        int count = mp.size();   // number of unique characters
        int i = 0, j = 0;

        int minLen = INT_MAX;
        int start = 0;

        while(j < s.length()){

            // calculation part
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;

                if(mp[s[j]] == 0)
                    count--;
            }

            // when all characters matched
            while(count == 0){

                // update minimum window
                if(j - i + 1 < minLen){
                    minLen = j - i + 1;
                    start = i;
                }

                // remove element from window
                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]++;

                    if(mp[s[i]] == 1)
                        count++;
                }

                i++;
            }

            j++;
        }

        if(minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};


int main(){
    Solution obj;

    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << obj.minWindow(s,t) << endl;

    return 0;
}
/*
===============================================================
Problem: Minimum Window Substring
LeetCode: 76

Given two strings s and t, return the minimum window substring
of s such that every character in t (including duplicates)
is included in the window.

If there is no such substring, return "".

Example:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"

Pattern: Sliding Window (Variable Size Window)
Approach: Aditya Verma Style
===============================================================
*/
/*
===============================================================
Key Idea (Aditya Verma Sliding Window)

1. Build frequency map of pattern.
2. Expand window using j.
3. Decrease frequency when character found.
4. When count == 0 → all characters matched.
5. Start shrinking window with i to minimize length.

Time Complexity: O(n)
Space Complexity: O(1) (at most 256 characters)
===============================================================
*/
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    
    int search(string &pat, string &txt) {

        unordered_map<char,int> mp;

        // Store frequency of characters from pattern
        for(char c : pat){
            mp[c]++;
        }

        int k = pat.size();

        int i = 0;
        int j = 0;

        int count = mp.size();   // number of unique characters
        int ans = 0;

        // Sliding Window
        while(j < txt.size()){

            // Include current character
            if(mp.find(txt[j]) != mp.end()){

                mp[txt[j]]--;

                if(mp[txt[j]] == 0){
                    count--;
                }
            }

            // Window size < k
            if(j - i + 1 < k){
                j++;
            }

            // Window size == k
            else if(j - i + 1 == k){

                // If all characters matched
                if(count == 0){
                    ans++;
                }

                // Remove character leaving the window
                if(mp.find(txt[i]) != mp.end()){

                    mp[txt[i]]++;

                    if(mp[txt[i]] == 1){
                        count++;
                    }
                }

                // Slide window
                i++;
                j++;
            }
        }

        return ans;
    }
};

int main(){

    Solution obj;

    string txt = "forxxorfxdofr";
    string pat = "for";

    int result = obj.search(pat, txt);

    cout << "Number of Anagram Occurrences: " << result << endl;

    return 0;
}


/*
====================================================================
PROBLEM: Count Occurrences of Anagrams (Sliding Window)
====================================================================

Given:
- A text string (txt)
- A pattern string (pat)

Find how many substrings of txt are anagrams of pat.

--------------------------------------------------------------------
Example
--------------------------------------------------------------------

txt = "forxxorfxdofr"
pat = "for"

Substrings of size 3:

for → anagram ✔
orx → ✖
rxx → ✖
xxo → ✖
xor → ✖
orf → anagram ✔
rfx → ✖
fxd → ✖
xdo → ✖
dof → ✖
ofr → anagram ✔

Total anagram occurrences = 3


--------------------------------------------------------------------
OPTIMAL APPROACH (Fixed Size Sliding Window)
--------------------------------------------------------------------

Window size = length of pattern (k)

Steps:

1. Store frequency of pattern characters in hashmap
2. Maintain a variable "count" = number of unique characters
3. Expand window by moving pointer j
4. If character exists in map:
       decrease its frequency
       if frequency becomes 0 → decrease count
5. When window size becomes k:
       if count == 0 → anagram found
6. Before sliding window:
       restore the frequency of character leaving window


--------------------------------------------------------------------
Sliding Window Visualization
--------------------------------------------------------------------

txt = "forxxorfxdofr"
pat = "for"

Window size = 3

[for]xxorfxdofr → anagram
f[orx]xorfxdofr
fo[rxx]orfxdofr
for[xxo]rfxdofr
...
xxorfxd[ofr] → anagram


--------------------------------------------------------------------
Key Idea
--------------------------------------------------------------------

If:

count == 0

All characters of pattern are matched in the window.

So current substring is an anagram.


--------------------------------------------------------------------
Time Complexity
--------------------------------------------------------------------

O(N)

Each character is processed once.


--------------------------------------------------------------------
Space Complexity
--------------------------------------------------------------------

O(K)

Where K = number of unique characters in pattern.


--------------------------------------------------------------------
Pattern Used
--------------------------------------------------------------------

Fixed Size Sliding Window

Common problems using this pattern:

• Maximum Sum Subarray of Size K
• First Negative Number in Window
• Count Occurrences of Anagrams
• Sliding Window Maximum

====================================================================
*/
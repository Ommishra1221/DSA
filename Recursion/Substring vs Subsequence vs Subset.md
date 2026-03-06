Substring vs Subsequence vs Subset

1️⃣ Substring
Definition

A substring is a continuous (contiguous) part of a string.

👉 Characters must appear in the same order and continuously.

Example

String:

S = "abc"

Possible substrings:

"a"
"b"
"c"
"ab"
"bc"
"abc"

❌ Not substrings:

"ac"

because characters are not continuous.

Visualization
abc

a
ab
abc
 b
 bc
  c

We always take continuous characters.

Number of Substrings

If string length = n

Formula:

n(n+1)/2

Example:

n = 3

3(3+1)/2
= 6 substrings

Matches:

a
b
c
ab
bc
abc
Typical Interview Problems

Examples:

Longest substring without repeating characters

Longest palindromic substring

Count substrings

Sliding window problems

Substring problems often use:

Sliding Window
Two Pointers
2️⃣ Subsequence
Definition

A subsequence is a sequence that can be derived from a string by removing characters without changing order.

👉 Characters do NOT need to be continuous.

Example

String:

S = "abc"

Subsequences:

""
"a"
"b"
"c"
"ab"
"ac"
"bc"
"abc"

Notice:

"ac"

is allowed because order is preserved.

Visualization
abc

Take / Not take decisions

        ""
       /  \
      ""  "a"
     /  \  /  \
    "" "b" "a" "ab"
Number of Subsequences

If string length = n

2^n

Example:

n = 3

2³ = 8 subsequences

Including empty string.

Why 2ⁿ ?

Because each character has 2 choices:

Include
Exclude
Typical Interview Problems

Subsequence problems use:

Recursion
Backtracking
Dynamic Programming

Examples:

Longest common subsequence

Longest increasing subsequence

Print all subsequences

Subsequence sum

3️⃣ Subset

Subset is related to sets / arrays, not specifically strings.

Definition

A subset is a selection of elements from a set where order does not matter.

Example

Set:

{1,2,3}

Subsets:

{}
{1}
{2}
{3}
{1,2}
{1,3}
{2,3}
{1,2,3}
Number of Subsets

If set size = n

2^n

Same logic:

Each element has two choices

include
exclude
Important Note

Subsets ignore order.

Example:

{1,2}
{2,1}

These are same subset.

Typical Interview Problems

Subset problems appear in:

Print all subsets

Subset sum

Combination sum

Power set

Subsets with duplicates

4️⃣ Difference Between Them
Feature	Substring	Subsequence	Subset
Data type	String	String	Set / Array
Order matters	Yes	Yes	No
Continuity required	Yes	No	No
Formula	n(n+1)/2	2ⁿ	2ⁿ
Example allowed	"ab"	"ac"	{1,3}
5️⃣ Quick Example

String:

abc
Substrings
a
b
c
ab
bc
abc

Total:

6
Subsequences
""
a
b
c
ab
ac
bc
abc

Total:

8
Subsets (if elements are set)
{}
{a}
{b}
{c}
{a,b}
{a,c}
{b,c}
{a,b,c}

Total:

8
6️⃣ Memory Trick (Important)

Remember this:

Substring → continuous

Subsequence → order maintained

Subset → order ignored
7️⃣ Interview Tip

If interviewer asks:

Difference between substring and subsequence

Answer:

A substring is a contiguous part of a string, while a subsequence allows removing characters without changing order and does not require continuity.
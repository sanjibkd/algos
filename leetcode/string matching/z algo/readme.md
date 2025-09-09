**What:** Efficient way of searching occurences of a **pattern** inside a **text**.

**Why:** Naive approach of checking for pattern at every index of the text is O(m.n) time. This one has O(m + n) time. There are other efficient algorithms too, such as KMP, but this one is much simpler.

**How:**

**Step 1:** Construct Z array for _pattern + "$" + text_

For a string s[0 ... n - 1], each element Z[i] of Z[0 ... n - 1] represents the length of the longest subtring of s, starting at index i that is a prefix of s.

That is, Z[i] = l ==> s[i ... i + l - 1] matches s[0 ... l - 1].

Z[0] = 0 by definiton, as we do not want to compare the full string with itself.

**Example:** For s = "aabxaab", Z = [0, 1, 0, 0, 3, 1, 0]

A naive algorithm to construct Z array can be O(n^2). There exists an efficient algorithm to construct Z array in O(n).

**Step 2:** To find all occurences of pattern in text, search for all Z[i]'s that are _length(pattern)_

**Step 3:** To get the actual match positions in text, subtract _length(pattern) + 1 (for $)_ from the i's.

**Related Problems:**

- Find all occurrences of subarray in array
- Find the longest prefix which is also a suffix
- Find the minimum number of characters to add at front for palindrome
- String rotations of each other

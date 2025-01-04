/*
  Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
  Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.
  A palindrome is a string that reads the same forwards and backwards.
  A subsequence of a string is a new string generated from the original string with some characters
  (can be none) deleted without changing the relative order of the remaining characters.
  For example, "ace" is a subsequence of "abcde".
  
  Example 1:
    Input: s = "aabca"
    Output: 3
    Explanation: The 3 palindromic subsequences of length 3 are:
      - "aba" (subsequence of "aabca")
      - "aaa" (subsequence of "aabca")
      - "aca" (subsequence of "aabca")
  
  Example 2:
    Input: s = "adc"
    Output: 0
    Explanation: There are no palindromic subsequences of length 3 in "adc".

  Example 3:
    Input: s = "bbcbaba"
    Output: 4
    Explanation: The 4 palindromic subsequences of length 3 are:
      - "bbb" (subsequence of "bbcbaba")
      - "bcb" (subsequence of "bbcbaba")
      - "bab" (subsequence of "bbcbaba")
      - "aba" (subsequence of "bbcbaba")
      
  Constraints:
    3 <= s.length <= 105
    s consists of only lowercase English letters.

  Level: Medium
*/
// T: O(n), S: O(1)
int countPalindromicSubsequence(string s) {
    vector<int> firstIdx(26, -1);
    vector<int> lastIdx(26, -1);
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        int idx = s[i] - 'a';
        if (firstIdx[idx] < 0) firstIdx[idx] = i;
        lastIdx[idx] = i;
    }
    int res = 0;
    for (int i = 0; i < 26; ++i) {
        if (firstIdx[i] < 0) continue;
        if (lastIdx[i] - firstIdx[i] < 2) continue;
        res += countUnique(s, firstIdx[i], lastIdx[i]);
    }
    return res;
}

int countUnique(const string& s, int start, int end) {
    unordered_set<char> mids;
    for (int i = start + 1; i < end; ++i)
        mids.insert(s[i]);
    return mids.size();
}

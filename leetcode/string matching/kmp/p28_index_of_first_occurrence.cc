/*
  Given two strings needle and haystack, return the index of the first occurrence of
  needle in haystack, or -1 if needle is not part of haystack.

  Example 1:  
    Input: haystack = "sadbutsad", needle = "sad"
    Output: 0
    Explanation: "sad" occurs at index 0 and 6.
    The first occurrence is at index 0, so we return 0.
  
  Example 2:
    Input: haystack = "leetcode", needle = "leeto"
    Output: -1
    Explanation: "leeto" did not occur in "leetcode", so we return -1.
  
  Constraints:
    1 <= haystack.length, needle.length <= 104
    haystack and needle consist of only lowercase English characters.

  Level: Easy
*/
// KMP algorithm
// T: O(m + n), S: O(m)
int strStr(string haystack, string needle) {
  int n = haystack.size(), m = needle.size();
  // lps[q] = Longest prefix of substring needle[1 ... q] that is
  // also a proper suffix of the same substring needle[1 ... q]
  // E.g. needle: "A A A X A A A A"
  //         lps: [0 1 2 0 1 2 3 3]
  vector<int> lps(m + 1, 0);
  preprocess(needle, lps);

  // Match
  int j = 0; // number of characters in needle that has matched so far
  for (int i = 0; i < n; ++i) {
    while (j > 0 && haystack[i] != needle[j]) j = lps[j];
    if (needle[j] == haystack[i]) ++j;
    if (j == m) return i - m + 1;
  }
  return -1;
}

void preprocess(const string& needle, vector<int>& lps) {
  int m = needle.size();
  for (int j = 2, k = 0; j <= m; ++j) {
    while (k > 0 && needle[j - 1] != needle[k]) k = lps[k];
    if (needle[j - 1] == needle[k]) ++k;
    lps[j] = k;
  }
}

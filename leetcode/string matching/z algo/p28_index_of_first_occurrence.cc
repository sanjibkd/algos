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
// Z array
// T: O(m + n), S: O(m + n)
int strStr(string haystack, string needle) {
  int m = haystack.size(), n = needle.size();
  string s = needle + "$" + haystack;
  vector<int> z(s.size());
  zfunc(s, z);
  for (int i = 0; i < m; ++i)
    if (z[i + n + 1] == n) return i;
  return -1;
}

void zfunc(const string& s, vector<int>& z) {
  int n = s.size();
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    // Reuse the previously computed value
    if (i <= r)
      z[i] = min(r - i + 1, z[i - l]);
    // Try to extend the Z-box beyond r
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
      ++z[i];
    // Update (l, r) if Z-box is extended
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
}

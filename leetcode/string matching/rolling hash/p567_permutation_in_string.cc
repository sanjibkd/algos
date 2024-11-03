/*
  Given two strings s1 and s2, return true if s2 contains a permutation of s1,
  or false otherwise.
  In other words, return true if one of s1's permutations is the substring of s2.
  
  Example 1:
    Input: s1 = "ab", s2 = "eidbaooo"
    Output: true
    Explanation: s2 contains one permutation of s1 ("ba").

  Example 2:
    Input: s1 = "ab", s2 = "eidboaoo"
    Output: false

  Constraints:
    1 <= s1.length, s2.length <= 104
    s1 and s2 consist of lowercase English letters.

  Level: Medium
*/

// T: O(m + n), S: O(1)
// String matching: rolling hash
// Sliding window
bool checkInclusion(string s1, string s2) {
  int n1 = s1.size(), n2 = s2.size();
  if (n2 < n1) return false;
  vector<int> h1(26, 0), h2(26, 0);
  buildHash(s1, h1);
  buildHash(s2.substr(0, n1), h2);
  if (h1 == h2) return true;
  for (int i = n1; i < n2; ++i) {
    updateHash(s2[i - n1], s2[i], h2);
    if (h1 == h2) return true;
  }
  return false;
}

void buildHash(const string& s, vector<int>& h) {
  for (char c : s) ++h[c - 'a'];
}

void updateHash(char c1, char c2, vector<int>& h) {
  --h[c1 - 'a'];
  ++h[c2 - 'a'];
}

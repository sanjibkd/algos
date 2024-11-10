/*
  You are given two integers n and x.
  You have to construct an array of positive integers nums of size n where for every 0 <= i < n - 1,
  nums[i + 1] is greater than nums[i],
  and the result of the bitwise AND operation between all elements of nums is x.
  
  Return the minimum possible value of nums[n - 1].
  Example 1:
    Input: n = 3, x = 4
    Output: 6
    Explanation: nums can be [4,5,6] and its last element is 6.
  
  Example 2:
    Input: n = 2, x = 7
    Output: 15
    Explanation: nums can be [7,15] and its last element is 15.

  Constraints:
    1 <= n, x <= 10^8

  Level: Medium
*/

// T: O(1), S: O(1)
// Bit manipulation
long long minEnd(int n, int x) {
  // Intuition:
  //  - Say x = 10110
  //  - All 1s in x have to be preserved, but 0s can be replaced by 0/1
  //  - So, all numbers are of the form 1?11?
  //  - Smallest number (index = 0): replace ?? by 00
  //  - Next number (index = 1): replace ?? by 01
  //  - ... Result (index = n - 1): replace ?? by bit pattern of n - 1
  int p = n - 1;
  long long res = 0;
  string sx = bitset<64>(x).to_string();
  string sp = bitset<64>(p).to_string();
  for (int i = 63, j = 63; i >= 0; --i) {
    if (sx[i] == '1') continue;
    sx[i] = sp[j--];
  }
  res = stoll(sx, nullptr, 2);
  return res;
}

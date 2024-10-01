// T: O(n), S: O(k)
// Modulo arithmetic
bool canArrange(vector<int>& arr, int k) {
  vector<int> freqs(k, 0);
  for (int a : arr) ++freqs[(a % k + k) % k];
  if (freqs[0] % 2) return false;
  if (k % 2 == 0 && freqs[k / 2] % 2 != 0) return false;
  for (int i = 1; i <= k / 2; ++i)
    if (freqs[i] != freqs[k - i]) return false;
  return true;
}

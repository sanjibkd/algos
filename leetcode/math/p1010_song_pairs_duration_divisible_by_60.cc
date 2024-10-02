/*
  You are given a list of songs where the ith song has a duration of time[i] seconds.
  Return the number of pairs of songs for which their total duration in seconds is divisible by 60.
  Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.

  Example 1:
    Input: time = [30,20,150,100,40]
    Output: 3
    Explanation: Three pairs have a total duration divisible by 60:
      (time[0] = 30, time[2] = 150): total duration 180
      (time[1] = 20, time[3] = 100): total duration 120
      (time[1] = 20, time[4] = 40): total duration 60

  Example 2:
    Input: time = [60,60,60]
    Output: 3
    Explanation: All three pairs have a total duration of 120, which is divisible by 60.

  Constraints:
    1 <= time.length <= 6 * 104
    1 <= time[i] <= 500

  Level: Medium
*/

// T: O(n), S: O(1)
// Modulo arithmetic; counting frequencies; one pass
int numPairsDivisibleBy60(vector<int>& time) {
  int M = 60, res = 0;
  vector<int> freqs(M, 0);
  for (int t : time) {
    res += freqs[(M - t % M) % M];  // 2nd % M to handle t % M = 0 case 
    ++freqs[t % M];
  }
  return res;
}

// T: O(n), S: O(1)
// Modulo arithmetic; counting frequencies; two pass
int numPairsDivisibleBy60TwoPass(vector<int>& time) {
  int M = 60;
  vector<int> freqs(M, 0);
  for (int t : time) ++freqs[t % M];
  int res = 0;
  res += nc2(freqs[0]);
  res += nc2(freqs[M / 2]);
  for (int i = 1; i < M / 2; ++i)
    res += freqs[i] * freqs[M - i];
  return res;
}

int nc2(int n) {
  if (n < 2) return 0;
  return n % 2 ? n * ((n - 1) / 2) : (n / 2) * (n - 1);
}

class Solution {
  public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
      long long res = 0;
      sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());
      int n = maximumHeight.size();
      if (maximumHeight[0] < n) return -1;
      int x = INT_MAX;
      for (int mh : maximumHeight) {
        x = min(x, mh);
        if (x == 0) return -1;
        res += x;
        --x;
      }
      return res;
    }
};

class Solution {
  public:
      bool checkWithDifferenceArray(vector<int>& nums, vector<vector<int>>& queries, int k) {
          int n = nums.size();
          vector<int> diff(n + 1, 0);
  
          for (int i = 0; i <= k; i++) {
              int l = queries[i][0];
              int r = queries[i][1];
              int v = queries[i][2];
              diff[l] += v;
              if (r + 1 < n) diff[r + 1] -= v;
          }
  
          int currentSum = 0;
          for (int i = 0; i < n; i++) {
              currentSum += diff[i];
              if (nums[i] - currentSum > 0) return false;
          }
          return true;
      }
  
      int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
          if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) return 0;
  
          int left = 0, right = queries.size() - 1;
          int result = -1;
  
          while (left <= right) {
              int mid = left + (right - left) / 2;
  
              if (checkWithDifferenceArray(nums, queries, mid)) {
                  result = mid + 1;
                  right = mid - 1;
              } else {
                  left = mid + 1;
              }
          }
  
          return result;
      }
  };
  
class Solution {
  public:
      int maxAbsoluteSum(vector<int>& nums) {
          int n=nums.size();
          int currSum=nums[0];
          int maxSum=nums[0];
          for(int i=1;i<n;i++){
              currSum=max(nums[i],nums[i]+currSum);
              maxSum=max(maxSum,currSum);
          }
          int minSum=nums[0];
          currSum=nums[0];
          for(int i=1;i<n;i++){
              currSum=min(nums[i],nums[i]+currSum);
              minSum=min(minSum,currSum);
          }
          if(minSum<0)
          minSum=-minSum;
          return max(maxSum,minSum);
      }
  };
class Solution {
  public:
  
  
          int lowerBound(vector<int>&nums){
              int s=0,e=nums.size()-1;
              int in=nums.size();
              while(s<=e){
                  int mid=(s+e)/2;
  
                  if(nums[mid]<0){
                      s=mid+1;
                  }else if(nums[mid]>=0){
                      e=mid-1;
                      in=mid;
                  }
              }
              return in;
          }
  
          int upperBound(vector<int> &nums){
              int s=0,e=nums.size()-1;
              int in=nums.size();
              while(s<=e){
                  int mid=(s+e)/2;
  
                  if(nums[mid]<=0){
                      s=mid+1;
                  }else if(nums[mid]>0){
                      e=mid-1;
                      in=mid;
                  }
              }
              return in;
          }
      int maximumCount(vector<int>& nums) {
          int n=nums.size();
          int positiveCount=n-upperBound(nums);
          int negativeCount=lowerBound(nums);
          return max(positiveCount,negativeCount);
      }
  };
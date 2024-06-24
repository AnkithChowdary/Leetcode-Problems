class Solution {
  public int maxProduct(int[] nums) {
      int n=nums.length;
       int c=nums[0];
    
  for (int i=1,max=c,min=c;i<n;i++) {
    
      if (nums[i] < 0){
          int t=max;
          max=min;
          min=t;
      }
         
      max = Math.max(nums[i],max*nums[i]);
      min= Math.min(nums[i],min*nums[i]);
      c = Math.max(c, max);
  }
  return c;
  }
}


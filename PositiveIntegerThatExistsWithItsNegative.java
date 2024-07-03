import java.util.Arrays;

class Solution {
  public int findMaxK(int[] nums) {
      Arrays.sort(nums);
      int i=0,j=nums.length-1;
      while(i<j){
          if(nums[j]==-nums[i]){
              return nums[j];
          }else if(-nums[i]>nums[j]){
              i++;
          }else
          {
              j--;
          }
      }
      return -1;
  }
}
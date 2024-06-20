import java.util.*;
class Solution {
  public int longestConsecutive(int[] nums) {
      int n=nums.length;
      if(n==0)
          return 0;

      int longest=1;
      Set<Integer>s=new HashSet<>();

      
      for (int i=0;i<n;i++) {
          s.add(nums[i]);
      }

      
      for (int num : s) {
          
          if (!s.contains(num-1)) {
              
              int c=1;
              int st = num;
              while (s.contains(st + 1)) {
                  st++;  //Start
                  c++;   //Count
              }
              longest=Math.max(longest, c);
          }
      }
      return longest;
  }
  }
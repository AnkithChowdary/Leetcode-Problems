class Solution {
  public int duplicateNumbersXOR(int[] nums) {
      HashMap<Integer, Integer> mp = new HashMap<>();
      int n = nums.length;

      
      for (int i=0;i<n;i++) {
          mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
      }

      int xorResult = 0;
      boolean found = false;

      
      for (Map.Entry<Integer, Integer> e:mp.entrySet()) {
          if (e.getValue()== 2){
              xorResult^=e.getKey();
              found=true;
          }
      }

     
      if (!found) {
          return 0;
      }

      return xorResult;
      
  }
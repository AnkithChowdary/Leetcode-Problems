import java.util.*;

class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> result = new ArrayList<>();
        if (nums == null || nums.length == 0) return result;

       
        Map<Integer, Integer>mp = new HashMap<>();
        for (int num : nums) {
            mp.put(num, mp.getOrDefault(num, 0) + 1);
        }
         int n=nums.length;
        
        
        for (Map.Entry<Integer, Integer> i : mp.entrySet()) {
            if (i.getValue()>n/3) {
                result.add(i.getKey());
            }
        }

        return result;
    }
}

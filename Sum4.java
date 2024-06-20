import java.util.*;

class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        Set<List<Integer>> s =new HashSet<>();
        int n=nums.length;

        for (int i = 0; i < n; i++) {
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            for (int j=i+1;j<n;j++) {
                if(j>i+1&&nums[j]==nums[j-1]){
                    continue;
                }
                int k = j + 1;
                int l = n - 1;

                while (k<l) {
                    long sum = (long) nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum < target) {
                        k++;
                    } else if (sum == target) {
                        List<Integer> li = Arrays.asList(nums[i], nums[j], nums[k], nums[l]);
                        s.add(li);
                        k++;
                        l--;
                    } else {
                        l--;
                    }
                }
            }
        }

        return new ArrayList<>(s);
    }
}

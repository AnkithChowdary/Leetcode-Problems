import java.util.*;

class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        Set<List<Integer>> s = new HashSet<>();
        int n = nums.length;

        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                int k = j + 1;
                int l = n - 1;

                while (k < l) {
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

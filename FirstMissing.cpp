class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool>ans(n+1,false);

        
        for (int num : nums) {
            if (num>0 && num <= n) {
                ans[num]=true;
            }
        }

        
        for (int i = 1; i <= n; i++) {
            if (!ans[i]) {
                return i;
            }
        }

    
        return n + 1;
    }
};
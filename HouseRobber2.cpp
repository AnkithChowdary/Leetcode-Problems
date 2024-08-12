class Solution {
public:

    int robHelper(vector<int>& nums,int i,int j,vector<int>&v) {
        if(i>j){
            return 0;
        }

        if(v[i]!=-1) {
            return v[i];
        }

        
        int rob1=nums[i]+robHelper(nums,i+2,j,v);

        
        int rob2 = robHelper(nums, i+1, j,v);

       
        return v[i] = max(rob1, rob2);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }

       
        vector<int>v1(n,-1);
        vector<int>v2(n,-1);

        
        int option1 = robHelper(nums, 0, n-2,v1);

        
        int option2 = robHelper(nums,1,n-1,v2);

       
        return max(option1,option2);
    }
};

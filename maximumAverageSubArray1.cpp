
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int csum=0;
        for(int i=0;i<k;i++){
            csum+=nums[i];
        }
        int maxSum=csum;
        for(int j=k;j<nums.size();j++){
            csum+=nums[j]-nums[j-k];
            maxSum=max(csum,maxSum);
        }
        return maxSum/(double)k;
    }
};
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>v;
        for (int i=0;i<nums.size();i++){
            int sum=0;
            for (int j=i; j<nums.size();j++){
                sum+=nums[j];
                v.push_back(sum);
            }
        }
        sort(v.begin(),v.end());
        
        
        long long ans=0;
        for (int i=left-1;i< right;i++){
            ans+=v[i];
        }
        
      
        return ans%1000000007;
    }
};
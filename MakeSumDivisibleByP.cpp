class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
       
        int curr=0;
        
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        sum=(sum+nums[i])%p;
         int target=sum%p;
         if(target==0)
         return 0;
         int ans=n;
         unordered_map<int,int>mp;
         mp[0]=-1;
        
        for(int i=0;i<n;i++){
        curr=(curr+nums[i])%p;
        int r=(curr-target+p)%p;
        if(mp.find(r)!=mp.end()){
           ans=min(ans,i-mp[r]); 
        }
        mp[curr]=i;
            
        }

        return ans<n?ans:-1;
    }
};
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        set<pair<int,int>>ans;
        int i=0, j=1;
        while(j<nums.size()){
            int d=nums[j]-nums[i];
            if(d==k){
                ans.insert({nums[i],nums[j]});
                i++,j++;
            }else if(d>k){
                i++;
            }else{
                j++;
            }
            if(i==j){
                j++;
            }
        }
        return ans.size();
    }
};
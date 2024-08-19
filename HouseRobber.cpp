class Solution {
public:
     
     int t[101];
     int robHelper(vector<int>& nums, int i){
        if(i>=nums.size()){
            return 0;
        }else{
            if(t[i]!=-1){
                return t[i];
            }
            int rob1=nums[i]+robHelper(nums,i+2);
            int rob2=0+robHelper(nums,i+1);
            return t[i]= max(rob1,rob2);

        }
     }
    int rob(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return robHelper(nums,0);
        
    }
};
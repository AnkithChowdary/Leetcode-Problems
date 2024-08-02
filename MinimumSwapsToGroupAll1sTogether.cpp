class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int tones=0;
        int n=nums.size();
        for(int n:nums){
            if(n==1){
                tones++;
            }
        }
        if(tones==nums.size()||tones==0){
            return 0;
        }
        int maxC=0;
        for(int i=0;i<tones;i++){
            if(nums[i]==1){
                maxC++;
            }
        }
        int c=maxC;
        for(int i=1;i<nums.size();i++){
              c-=nums[i-1];
              c+=nums[(i+tones-1)%n];
              maxC=max(c,maxC);
        }
        return tones-maxC;
    }
};
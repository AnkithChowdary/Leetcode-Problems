class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum=0;
        vector<int>mp(1001,0);
        for(auto num:skill){
        sum+=num;
        mp[num]++;
        }
        
        int n=skill.size();
        
        
        if(sum%(n/2)!=0)
        return -1;
        int target=sum/(n/2);
        long long ans=0;

        for(int num:skill){
            int counterPart=target-num;
            if(mp[counterPart]==0)
            return -1;

            ans+=(long long)num*(long long)counterPart;
            mp[counterPart]--;
        }
        return ans/2;  

    }
};
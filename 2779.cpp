class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>>interval(n);
        for(int i=0;i<n;i++){
            interval[i]={nums[i]-k,nums[i]+k};
        }

        sort(begin(interval),end(interval));

        deque<int>deq;
int ans=0;
        for(pair<int,int>& inter:interval){
            while(!deq.empty()&&deq.front()<inter.first){
                deq.pop_front();
            }
            deq.push_back(inter.second);

            ans=max(ans,(int)deq.size());
        }
        return ans;
    }
};
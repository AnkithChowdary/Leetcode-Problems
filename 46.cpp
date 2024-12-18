class Solution {
public:
    vector<vector<int>>ans;
    int n;
    unordered_set<int>s;
    void solve(vector<int>temp,vector<int>nums){
        if(temp.size()==n){
        ans.push_back(temp);
        return;
        }

        for(int i=0;i<n;i++){
           if(s.find(nums[i])==s.end()){
            temp.push_back(nums[i]);
            s.insert(nums[i]);
            solve(temp,nums);
            temp.pop_back();
            s.erase(nums[i]);
           }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        n=nums.size();
        solve(temp,nums);
        return ans;
    }
};
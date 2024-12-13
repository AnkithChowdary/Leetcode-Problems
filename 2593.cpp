class Solution {
public:
    long long findScore(vector<int>& nums) {
        

        int n=nums.size();

         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        vector<pair<int, int>> arr(n);
        for(int i=0;i<n;i++){
            q.push({nums[i],i});
        }
      
        long long ans=0;
        
       vector<bool>visited(n,false);

      while(!q.empty()){
        auto [ele,in]=q.top();
        q.pop();
        
        if(!visited[in]){
            ans+=ele;
            visited[in]=true;
        
        if(in-1>=0&&visited[in-1]==false)
        visited[in-1]=true;

        if(in+1<n&&visited[in+1]==false)
        visited[in+1]=true;

        }
       }
       return ans;

    }
};
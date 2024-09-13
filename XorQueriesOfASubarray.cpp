class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n=arr.size();
        int m=queries.size();
        vector<int>ans(m);
         vector<int>prefixSum(n);
         prefixSum[0]=arr[0];
         for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]^arr[i];
         }
            for(int j=0;j<m;j++){
                int x=queries[j][0];
                int y=queries[j][1];
                if(x==0)
                ans[j]=prefixSum[y];                    // Does index does that job   0 to y xor
                else
                ans[j]=prefixSum[y]^prefixSum[x-1];    // xors  0-y=1   2  3  4    0 to x-1 
            }                                           // We are left with x to y
        
        return ans;
    }
};
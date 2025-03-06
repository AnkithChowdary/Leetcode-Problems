class Solution {
  public:
      vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
          int n=grid.size();
          unordered_map<int,int>mp;
          for(int i=0;i<n;i++){
              for(int j=0;j<grid[0].size();j++){
                  mp[grid[i][j]]++;
              }
          }
          vector<int>res(2,0);
          for(auto it:mp){
              if(it.second>1){
                  res[0]=it.first;
              }
          }
          for(int i=1;i<=n*n;i++){
              if(mp.find(i)==mp.end())
              res[1]=i;
          }
          
          return res;
      }
  };
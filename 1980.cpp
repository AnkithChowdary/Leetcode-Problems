class Solution {
  public:
  
  
      string solve(int &n,string s,unordered_set<string>& mp){
          if(s.size()==n){
              if(mp.find(s)==mp.end()){
                  return s;
              }
              return "";
          }
  
          for(char ch:{'0','1'}){
              
                  s.push_back(ch);
                  string res=solve(n,s,mp);
                  if(!res.empty())
                  return res;
                  s.pop_back();
              
          }
          return "";
      }
      string findDifferentBinaryString(vector<string>& nums) {
          int n=nums[0].size();
          string s="";
          unordered_set<string>mp(nums.begin(),nums.end());
          return solve(n,s,mp);
      }
  };
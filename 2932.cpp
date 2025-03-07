class Solution {
  public:
      int maximumStrongPairXor(vector<int>& nums) {
          int res=0;
  
          for(int x:nums){
              for(int y:nums){
                  if(abs(x-y)<=min(x,y)){
                      res=max(res,x^y);
                  }
              }
          }
          return res;
      }
  };
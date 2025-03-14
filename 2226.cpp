class Solution {
  public:
  
      bool check(vector<int>&candies,long long k,int candiesCount){
          long long int maxChildren=0;
          for(int i=0;i<candies.size();i++){
              maxChildren+=candies[i]/candiesCount;
          }
  
          return maxChildren>=k;
      }
      int maximumCandies(vector<int>& candies, long long k) {
          int n=candies.size();
          int maxVal=0;
          for(int i=0;i<n;i++){
              maxVal=max(maxVal,candies[i]);
          }
          int l=0,r=maxVal;
  
          while(l<r){
              int mid=(l+r+1)/2;
  
              if(check(candies,k,mid)){
                  l=mid;
              }else{
                  r=mid-1;
              }
          }
          return l;
      }
  
      
  };
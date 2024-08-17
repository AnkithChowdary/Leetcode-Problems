class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
       
        int maxi=INT_MIN;
        int re=0,curr=0;    
        for(int n:values){
          re=max(re,curr+n);
          curr=max(curr,n)-1;  
        }
        return re;
    }
};
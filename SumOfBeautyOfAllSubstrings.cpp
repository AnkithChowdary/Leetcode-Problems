class Solution {
public:
    int beautySum(string s) {
    int ans=0;
    int n=s.length();
    
    for(int i=0;i<n;i++){
        unordered_map<char,int>mp;
        
        for(int j=i;j<n;j++) {
            mp[s[j]]++;
            
            int maxi=INT_MIN;
            int mini=INT_MAX;
            
            for(auto &pair:mp){
                maxi=max(maxi,pair.second);
                mini=min(mini,pair.second);
            }
            
            ans+=(maxi-mini);
        }
    }
    
    return ans;
    }
};
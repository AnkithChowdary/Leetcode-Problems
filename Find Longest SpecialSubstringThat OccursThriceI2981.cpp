class Solution {
public:
    int maximumLength(string s) {
        int n=s.length();
        map<pair<char,int>,int>mp;

        for(int i=0;i<n;i++){
            char currCh=s[i];
            int len=0;
            for(int j=i;j<n;j++){
                if(s[j]==currCh){
                    len++;
                    mp[{currCh,len}]++;
                }else{
                break;
                }
            }
        }
        int ans=0;
        for(auto &it:mp){
            int len=it.first.second;
             char ch=it.first.first;
             int freq=it.second;
            if(freq>=3&&len>ans)
            ans=len;
        }
        return ans==0?-1:ans;
    }
};
class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        int black=0;
        for(char ch:s){
            if(ch=='0')
            ans+=(long long)black;
            else
            black++;
        }
        return ans;
    }
};
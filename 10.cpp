class Solution {
public:
// Without dp
    bool solve(string s,string p){
        if(p.length()==0)
        return s.length()==0;

        bool first=false;

        if(s.length()>0&&(p[0]==s[0]||p[0]=='.'))
        first=true;

        if(p.length()>=2&&p[1]=='*')
        return (solve(s,p.substr(2)))||(first&&solve(s.substr(1),p));
        else
        return first&&solve(s.substr(1),p.substr(1));

    }
    bool isMatch(string s, string p) {
        return solve(s,p);
    }
};


class Solution {
public:
     int dp[21][21];
    bool solve(string s,string p,int i,int j){
        if(j==p.length())
        return i==s.length();
        if(dp[i][j]!=-1)
        return dp[i][j];
        bool first=false;

        if(i<s.length()&&(p[j]==s[i]||p[j]=='.'))
        first=true;

        if(j+1<p.length()&&p[j+1]=='*')
        return dp[i][j] = (solve(s, p, i, j + 2)) || (first && solve(s, p, i + 1, j)); // not take or not take
        else
        return dp[i][j]=first&&solve(s,p,i+1,j+1);

    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return solve(s,p,0,0);
    }
};
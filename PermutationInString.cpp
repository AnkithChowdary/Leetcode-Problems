class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(),s1.end());
        int len1=s1.length();
        int len2=s2.length();
        for(int i=0;i<=len2-len1;i++){
            string window=s2.substr(i,len1);
            sort(window.begin(),window.end());
            if(window==s1)
            return true;
        }

        return false;
    }
};
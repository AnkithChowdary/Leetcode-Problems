class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.length()-1;
        while (i<j) {
            if (s[i]!=s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool helper(string s,int i,int j,bool skipped) {
        while (i<j){
            if(s[i]!=s[j]){
                if(skipped) {
                    return false;
                }
              
                return helper(s,i+1,j,true)||helper(s,i,j-1,true);
            }
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        return helper(s,0,s.length()-1,false);
    }
};

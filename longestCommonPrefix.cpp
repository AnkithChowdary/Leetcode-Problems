class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int i=0;
        while(true){
            char ch=0;
            for(auto s:strs){
                if(i>=s.size()){
                    ch=0;
                    break;
                }
               if(ch==0){
                ch=s[i];
               }else if(s[i]!=ch){
                ch=0;
                break;
               }
            }
            if(ch==0){
                break;
            }
            ans.push_back(ch);
            i++;
        }
        return ans;
    }
};
class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ans.empty()==true){
                ans.push_back(ch);
            }else{
                if(ch==ans.back()){
                    ans.pop_back();
                }else{
                    ans.push_back(ch);
                }
            }
        }
        return ans;
    }
};
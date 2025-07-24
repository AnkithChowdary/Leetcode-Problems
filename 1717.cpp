
//Problem Link:https://leetcode.com/problems/maximum-score-from-removing-substrings/?envType=daily-question&envId=2025-07-23
class Solution {
public:
    string removeSubstr(string &s,string &matchStr){
        stack<char>st;
        for(auto &ch:s){
            if(ch==matchStr[1]&&!st.empty()&&st.top()==matchStr[0]){
                st.pop();
            }else{
                st.push(ch);
            }
        }
        string temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;


    }
    int maximumGain(string s, int x, int y) {
        // Here we can delete first element which is having maximum points to get the max value
        // In first pass delete the element which has max points
        // IN second pass delete the string which is having min points
        int n=s.length();
        int score=0;
        string maxStr=(x>y)?"ab":"ba";
        string minStr=(y<x)?"ba":"ab";

        string temp_firstStr=removeSubstr(s,maxStr);
        int len=temp_firstStr.length();
        int charsRemoved=n-len;

       
        score+=(charsRemoved/2)*max(x,y);

        // pass two
        string ans=removeSubstr(temp_firstStr,minStr);
        int nLen=ans.length();
        charsRemoved=len-nLen;
        score+=(charsRemoved/2)*min(x,y);

        return score;

    }
};
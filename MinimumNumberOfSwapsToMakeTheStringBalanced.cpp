class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='[')
            st.push(s[i]);
            else if(!st.empty())
                st.pop();             // Removing the balanced one
        }
        return (st.size()+1)/2;
    }
};
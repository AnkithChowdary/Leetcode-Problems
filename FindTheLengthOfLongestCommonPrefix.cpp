class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string>s;
        int maxLen=0;
        for(int num:arr1){
            string a=to_string(num);
            for(int i=1;i<=a.size();i++){
                s.insert(a.substr(0,i));            // All th possible prefixes in the hashset
            }
        }

        for(int num:arr2){
            string b=to_string(num);
            for(int i=1;i<=b.size();i++){
                string pre=b.substr(0,i);
                if(s.find(pre)!=s.end())
                maxLen=max(maxLen,i);
            }
        }
        return maxLen;
    }
};
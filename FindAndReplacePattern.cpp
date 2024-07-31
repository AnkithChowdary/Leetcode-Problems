class Solution {
public:

    string normalise(string str){
         unordered_map<char,char>mp;
         char start='a';
         for(int i=0;i<str.length();i++){
            char c=str[i];
            if(mp.find(c)==mp.end()){
                mp[c]=start;
                start++;
            }
         }

         for(int i=0;i<str.length();i++){
            str[i]=mp[str[i]];
         }
         return str;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        //Converting into abcd..
        string newSt=normalise(pattern);
       vector<string>ans;
       for(int i=0;i<words.size();i++){
        string c=words[i];
        string nm=normalise(c);
        if(nm==newSt)
        ans.push_back(c);
       }
       return ans;
    }
};
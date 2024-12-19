class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mp1;
        unordered_map<string,char>mp2;
         stringstream st(s);
         vector<string>words;
         string word;
         int n=pattern.size();
         while(st>>word){
            words.push_back(word);
         }

         if(pattern.size()!=words.size())
         return false;

         for(int i=0;i<n;i++){
            char ch=pattern[i];
            string w=words[i];
            if(mp1.count(ch)&&mp1[ch]!=w){
                return false;
            }
            if(mp2.count(w)&&mp2[w]!=ch)
            return false;

            mp1[ch]=w;
            mp2[w]=ch;
         }
         return true;

    }
};
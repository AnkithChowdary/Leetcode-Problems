class Solution {
public:
    string decodeMessage(string key, string message) {
        string ans="";
        unordered_map<char,char>mp;
        char start='a';
        int i=0;
        char space=' ';
        mp[space]=space;

        while(start<='z'&&i<key.length()){
            //If the character is in the map
            if(mp.find(key[i])!=mp.end()){
                  i++;
            }else{
                mp[key[i]]=start;
                start++;
                i++;
            }
        }
        for(int i=0;i<message.length();i++){
            char cchar=message[i];
            char mpchar=mp[cchar];
            ans.push_back(mpchar);
        }
        return ans;
    }
};
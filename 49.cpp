class Solution {
public:

   string generate(string w){
    int arr[26]={0};
    for(char ch:w)
    arr[ch-'a']++;

    string n="";

    for(int i=0;i<26;i++){
        int freq=arr[i];
        if(freq>0)
        n+=string(freq,i+'a');
    }
    return n;
   }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
      unordered_map<string,vector<string>>mp;
      vector<vector<string>>ans;
      for(int i=0;i<n;i++){
        string w=strs[i];
        string n=generate(w);
        mp[n].push_back(w);
      }

      for(auto it:mp)
      ans.push_back(it.second);

      return ans;
    }
};
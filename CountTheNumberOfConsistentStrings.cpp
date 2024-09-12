class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
      unordered_set<char>s(allowed.begin(),allowed.end());
      int count=0;
       
       
      
        for(string word:words){
            bool flag=true;
            for(char ch:word){
              if(s.find(ch)==s.end()){
                flag=false;
                break;
              }
            }

            if(flag){
                count++;
            }
        }
        return count;
    }
};

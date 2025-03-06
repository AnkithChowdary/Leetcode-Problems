class Solution {
  public:
  
  
      vector<int> findSubstring(string s, vector<string>& words) {
          vector<int>result;
          int wordLen=words[0].size();
          int wordsCount=words.size();
          int totalLen=wordLen*wordsCount;
  
          if(s.length()<totalLen)
          return result;
          
          unordered_map<string,int>freq;
          for(string word:words){
              freq[word]++;
          }
         for(int i=0;i<wordLen;i++){
              unordered_map<string,int>window;
  
              int left=i;
              int right=i;
              while(right+wordLen<=s.size()){
                  string word=s.substr(right,wordLen);
                  right+=wordLen;
                  if(freq.count(word)){
                      window[word]++;
                  
                  while(window[word]>freq[word]){
                      string leftWord=s.substr(left,wordLen);
                      window[leftWord]--;
                      left+=wordLen;
                  }
                  if(right-left==totalLen)
                  result.push_back(left);
  
              }else{
                  window.clear();
                  left=right;
              }
              }
         }
          // string temp;
          // for(int i=0;i<s.length();i++){
  
          //     if(temp.size()==len)
          //     {
          //         if(words.find(temp)==words.end()){
          //             result.push_back(i-2);
          //             string temp;
          //         }
  
          //     }
          //     temp.push_back(s[i]);
          // }
  
          return result;
          
      }
  };
  
  //  Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
  
  
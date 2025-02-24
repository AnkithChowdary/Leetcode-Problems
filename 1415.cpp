class Solution {
  public:
      void solve(int n,string s,vector<string>&happyStrings){
          if(s.size()==n)
          {
              happyStrings.push_back(s);
              return;
          }
          for(char ch:{'a','b','c'}){
              if(s.empty()||s.back()!=ch){
                  s.push_back(ch);
                  solve(n,s,happyStrings);
                  s.pop_back();
              }
          }
  
      }
      string getHappyString(int n, int k) {
          string s="";
          vector<string>happyStrings;
          solve(n,s,happyStrings);
          return (k>happyStrings.size())?"":happyStrings[k-1];
      }
  };
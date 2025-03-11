class Solution {
  public:
      int numberOfSubstrings(string s) {
          unordered_map<char, int> mp;
          int n = s.size();
          int i = 0, j = 0;
          int count = 0;
          
          while (j < n) {
              // Expand the window
              mp[s[j]]++;
              
              // Valid window: contains at least one of each 'a', 'b', 'c'
              while (mp.size() == 3) {
                  count += (n - j);  // All substrings starting from i to n are valid
                  mp[s[i]]--;
                  if (mp[s[i]] == 0) {
                      mp.erase(s[i]);
                  }
                  i++;
              }
              
              j++;
          }
          
          return count;
      }
  };
  
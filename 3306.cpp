class Solution {
  public:
      bool isVowel(char ch) {
          return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
      }
  
      long long countOfSubstrings(string word, int k) {
          int n = word.length();
          unordered_map<char, int> vowelCount;
          vector<int> nxtCons(n);
          
          int index = n; // Index of the next consonant from the right
          for (int i = n - 1; i >= 0; i--) {
              nxtCons[i] = index;
              if (!isVowel(word[i])) index = i; // Store consonant index
          }
  
          int i = 0, j = 0;
          long long count = 0;
          int consCount = 0;
  
          while (j < n) {
              char ch = word[j];
              if (isVowel(ch)) {
                  vowelCount[ch]++;
              } else {
                  consCount++;
              }
  
              // Shrink window if consonant count exceeds k
              while (consCount > k) {
                  char leftChar = word[i];
                  if (isVowel(leftChar)) {
                      vowelCount[leftChar]--;
                      if (vowelCount[leftChar] == 0) vowelCount.erase(leftChar);
                  } else {
                      consCount--;
                  }
                  i++;
              }
  
              // If the window has all vowels and k consonants, count substrings
              while (vowelCount.size() == 5 && consCount == k) {
                  int nextConsonantIndex = nxtCons[j];
                  count += nextConsonantIndex - j;
                  
                  char leftChar = word[i];
                  if (isVowel(leftChar)) {
                      vowelCount[leftChar]--;
                      if (vowelCount[leftChar] == 0) vowelCount.erase(leftChar);
                  } else {
                      consCount--;
                  }
                  i++;
              }
              j++;
          }
  
          return count;
      }
  };
  
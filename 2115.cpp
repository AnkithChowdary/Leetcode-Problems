class Solution {
  public:
      vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
          unordered_set<string> s(supplies.begin(), supplies.end());
          unordered_set<string> made; // To track already made recipes
          vector<string> ans;
          bool progress = true;
  
          while (progress) { 
              progress = false;
              for (int i = 0; i < recipes.size(); i++) {
                  if (made.count(recipes[i])) continue; // Skip already made recipes
                  
                  bool canMake = true;
                  for (const string& ing : ingredients[i]) {
                      if (!s.count(ing)) {
                          canMake = false;
                          break;
                      }
                  }
                  
                  if (canMake) {
                      ans.push_back(recipes[i]);
                      s.insert(recipes[i]); // Add to available supplies
                      made.insert(recipes[i]);
                      progress = true; // Mark progress to continue checking
                  }
              }
          }
  
          return ans;
      }
  };
  
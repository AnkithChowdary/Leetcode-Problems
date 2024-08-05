class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;
      
        for (string str:arr){
            mp[str]++;
        }
      
        int count=0;
        for (string str:arr){
            if (mp[str]==1){
                count++;
                if (count==k) {
                    return str;
                }
            }
        }
        
        return "";
    }
};



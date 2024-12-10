class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) 
            return s;
        
        vector<string> arr(numRows, "");
        int n = s.length();
        int i = 0;

        while (i < n) {
          
            for (int j = 0; j < numRows && i < n; j++) {
                arr[j] += s[i++];
            }
           
            for (int j = numRows - 2; j > 0 && i < n; j--) {
                arr[j] += s[i++];
            }
        }

        string ans = "";
        for (string &row : arr) {
            ans += row;
        }

        return ans;
    }
};

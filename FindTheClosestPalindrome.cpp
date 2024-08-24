class Solution {
public:
    string nearestPalindromic(string n) {
        vector<long>v;
        int len=n.length();
        bool isOdd=(len%2!=0);
        int mid=(len%2==0)?(len/2):(len/2+1);
        long firstHalf=stol(n.substr(0,mid));
        
        // Copy first half and create the palindrome
        v.push_back(findNearestPalindrome(to_string(firstHalf), isOdd));
        // Copy first half +1 and create the palindrome
        v.push_back(findNearestPalindrome(to_string(firstHalf + 1), isOdd));
        // Copy first half -1 and create the palindrome
        v.push_back(findNearestPalindrome(to_string(firstHalf - 1), isOdd));
        // All 9's case
        v.push_back(pow(10, len - 1) - 1);
        // 101, 1001, 10001.. Cases
        v.push_back(pow(10, len) + 1);

        long num = stol(n);
        long minDiff =LONG_MAX;
        long res;
        for (auto it : v) {
            if (it == num) continue;
            long currDiff = abs(it - num);
            if (currDiff < minDiff) {
                res = it;
                minDiff = currDiff;
            } else if (currDiff == minDiff) {
                res = min(res, it);
            }
        }
        return to_string(res);
    }


    long findNearestPalindrome(string firstHalf, bool isOdd) {
        string secondHalf = string(firstHalf.rbegin() + (isOdd ? 1 : 0), firstHalf.rend());
        return stol(firstHalf + secondHalf);
    }
};

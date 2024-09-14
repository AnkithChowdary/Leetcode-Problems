class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int highestNum = 0, maxLength = 0, streakLength = 0;

        for (int num : nums) {
            highestNum = max(highestNum, num);
        }

        for (int num : nums) {
            if (num == highestNum) {
                streakLength++;
            } else {
                maxLength = max(maxLength, streakLength);
                streakLength = 0;
            }
        }

        return max(maxLength, streakLength);
    }
};

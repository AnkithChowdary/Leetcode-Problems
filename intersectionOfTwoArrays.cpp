#include <vector>
#include <algorithm>
#include <iterator>

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        std::vector<int>re;
        std::set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),std::back_inserter(re));
        re.erase(std::unique(re.begin(), re.end()), re.end());
        
        return re;
    }
};

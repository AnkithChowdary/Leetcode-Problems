class Solution {
public:
    int findPivot(vector<int>& arr) {
        int s = 0, e = arr.size() - 1;
        int n = arr.size();
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (mid + 1 < n && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            if (mid > 0 && arr[mid] < arr[mid - 1]) {
                return mid - 1;
            }
            if (arr[s] >= arr[mid]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return -1;
    }
    
    int binarySearch(vector<int>& arr, int s, int e, int target) {
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        
        int pivot = findPivot(nums);
        
        if (pivot == -1) {
           
            return binarySearch(nums, 0, n - 1, target);
        }

       
        if (nums[pivot] == target) {
            return pivot;
        }
        
        if (target >= nums[0] && target <= nums[pivot]) {
            return binarySearch(nums, 0, pivot, target);
        } else {
            return binarySearch(nums, pivot + 1, n - 1, target);
        }
    }
};

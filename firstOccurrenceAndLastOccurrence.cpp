class Solution {
public:
void firstOccurrence(vector<int>arr,int target,int &index) {
  int start = 0, end = arr.size()-1;
  int mid = start + (end-start)/2;
  while(start <= end) {
    if(target < arr[mid])
      end = mid-1;
    else if(target == arr[mid]){
      index = mid;
     end = mid-1;
    }
     else
     start = mid+1;

mid = start + (end-start)/2;
     
  }

}
void lastOccurrence(vector<int>arr,int target,int &index) {
  int start = 0, end = arr.size()-1;
  int mid = start + (end-start)/2;
  while(start <= end) {
    if(target < arr[mid])
      end = mid-1;
    else if(target == arr[mid]){
      index = mid;
     start=mid+1;
    }
     else
     start = mid+1;

mid = start + (end-start)/2;
     
  }
}

    vector<int> searchRange(vector<int>& nums, int target) {
    vector<int>ans;
    int fo=-1,lo=-1;
    firstOccurrence(nums,target,fo);
    lastOccurrence(nums,target,lo);
    ans.push_back(fo);
    ans.push_back(lo);
    return ans;

    }
};
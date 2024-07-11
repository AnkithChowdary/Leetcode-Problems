class Solution {
public:
     int findMissingNumber(vector<int>&arr){
        int n=arr.size();
        sort(arr.begin(),arr.end());
    int start = 0, end = arr.size()-1;
    int ans=-1;
  int mid = start + (end-start)/2;
  while(start <= end) {
    int num=arr[mid];
    int index=mid;
    int diff=num-index;
    if(diff==0){
        start=mid+1;
    }
    else if(diff==1){
        ans=index;
        end=mid-1;
    }

   

mid = start + (end-start)/2;
     }

      if(ans==-1){
        return n;
    }
     return ans;
}
  
    int missingNumber(vector<int>& nums) {
        return findMissingNumber(nums);
    }
};
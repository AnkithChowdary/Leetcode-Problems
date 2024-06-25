class Solution {
  public int[] nextGreaterElement(int[] nums1, int[] nums2) {
      int n=nums1.length;
      int n1=nums2.length;
      int []ans=new int[nums1.length];
      
      for(int i=0;i<n;i++){
          boolean flag=false;
          for(int j=0;j<n1;j++){
              
              if(flag&&nums1[i]<nums2[j]){
                  ans[i]=nums2[j];
                  break;
              }

              if(nums2[j]==nums1[i]){
                  flag=true;
              }

              if(j==n1-1){
                  ans[i]=-1;
              }
              
          }
      }
      return ans;
  }
}
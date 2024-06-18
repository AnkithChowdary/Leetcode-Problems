
  class Solution {
    public int majorityElement(int[] nums) {
        int n=nums.length;
        int count=0;
        int ele=-1;
        for(int num:nums){
           if(count==0){
            ele=num;
            count=1;
           }
           else if(num==ele){
            count++;
           }else {
            count--;
           }
        }
        count=0;
        for(int num:nums){
            if(num==ele){
                count++;
            }

        }
        if(count>n/2){
            return ele;
        }
        return -1;
    }
}


class Solution {
  public double average(int[] salary) {
      double min=salary[0];
      double max=min;
      double ans=0;
      for(int i=0;i<salary.length;i++){
           if(salary[i]>max){
              max=salary[i];
           }
           if(salary[i]<min){
              min=salary[i];
           }
           ans+=salary[i];
      }
      ans-=(min+max);
    return ans/(salary.length-2);
  }
}
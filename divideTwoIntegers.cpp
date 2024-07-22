class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN&&divisor==-1)return INT_MAX;
      bool checker=true;
      if((dividend>0&&divisor<0)||(dividend<0&&divisor>0)){
        checker=false;
      }
      long long dividendx=abs(dividend);
      long long divisorx=abs(divisor);
      long long s=0,e=dividendx;
      long long ans=0;
      while(s<=e){
        long long mid=((e-s)>>1)+s;
        if(mid*divisorx<=dividendx){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
      }
      if(checker==false){
        return -ans;
      }
        return ans;
      

    }
};
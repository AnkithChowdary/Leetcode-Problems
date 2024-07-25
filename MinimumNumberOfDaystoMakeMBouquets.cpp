class Solution {
public:

    bool canMakeInDays(vector<int>v,int d,int m,int k){
        int c=0;
        for(int i=0;i<v.size();i++){
            if(v[i]<=d){
              c++;
            }
            if(c==k){
                c=0;
                m--;
                if(m==0)
                break;  
            }
            if(v[i]>d){
                c=0;
            }
        }
        return m==0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int r=(long long int)m*(long long int)k;
        if(bloomDay.size()<r){
            return -1;
        }
        int start=*min_element(bloomDay.begin(),bloomDay.end());
        int end=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(start<=end){
           int mid=(start+end)>>1;
           int d=mid;
           if(canMakeInDays(bloomDay,d,m,k)){
            ans=d;
            end=mid-1;
           }else{
            start=mid+1;
           }
        }
        return ans;

    }
};
class Solution {
public:
       bool ifKokoCanEat(vector<int>p,int h,int k){
        long long th=0;
        for(int i=0;i<p.size();i++){
            th+=ceil(p[i]/(double)k);
        }
        return th<=h;
       }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1;
        int ans=-1;
        int end=*max_element(piles.begin(),piles.end());
        while(start<=end){
            int mid=(start+end)/2;
            int k=mid;
            if(ifKokoCanEat(piles,h,k)){
                ans=k;
                end=mid-1;

            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};
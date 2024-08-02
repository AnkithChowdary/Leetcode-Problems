class Solution {
public:
    int countPrimes(int n) {
        if(n==0){
            return 0;
        }
        vector<bool>v(n,true);
        v[0]=v[1]=false;
        int ans=0;
        for(int i=2;i<n;i++){
        if(v[i]){
            ans++;
        
        int j=i*2;
        while(j<n){
            v[j]=false;
            j+=i;
        }
        }
        }
        
        return ans;
    }
};
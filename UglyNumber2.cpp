class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>v(n+1);
        int i2,i3,i5;
        i2=i3=i5=1;
        v[1]=1;
        for(int i=2;i<=n;i++){
            int n2=v[i2]*2;
            int n3=v[i3]*3;
            int n5=v[i5]*5;
            int mini=min({n2,n3,n5});
            if(mini==n2){
                v[i]=n2;
                i2++;
            }
            if(mini==n3){
                v[i]=n3;
                i3++;
            }
            if(mini==n5){
                v[i]=n5;
                i5++;
            }
        }
        return v[n];
    }
};
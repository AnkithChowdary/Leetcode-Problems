class Solution {
public:
    int numTeams(vector<int>& rating) {
       int n=rating.size();
       int total=0;
       for(int j=1;j<n-1;j++){
        int cSmallerLeft=0;
        int cLargerLeft=0;
        int cSmallerRight=0;
        int cLargerRight=0;
        for(int i=0;i<j;i++){
            if(rating[i]<rating[j]){
                cSmallerLeft++;
            }else if(rating[i]>rating[j]){
                cLargerLeft++;
            }
        }
        for(int k=j+1;k<n;k++){
            if(rating[j]<rating[k])
            cLargerRight++;
            else if(rating[j]>rating[k])
            cSmallerRight++;
        }
        total+=(cLargerLeft*cSmallerRight)+(cSmallerLeft*cLargerRight);
        
       } 
       return total;
    }
};
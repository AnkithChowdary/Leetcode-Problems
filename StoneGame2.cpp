class Solution {
public:
    int n;
    int dp[2][101][101];
    
    int solveA(vector<int>& piles,int person,int i,int m){
        if(i>=n){
            return 0;
        }
        if(dp[person][i][m]!=-1){
            return dp[person][i][m];
        }
        int result=(person==1)?-1:INT_MAX;
        int stones=0;
        // Checks all the possiblities 
        for(int x=1;x<=min(2*m,n-i);x++) {
            stones += piles[i + x - 1];
            if(person == 1) {   // Alice's turn
                result = max(result, stones + solveA(piles, 0, i + x, max(m, x)));
            } else {   // Bob's turn
                result=min(result,solveA(piles,1,i+x,max(m,x)));
            }
        }
        return dp[person][i][m] = result;
    }
    
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp,-1,sizeof(dp));
        return solveA(piles,1,0,1);
    }
};

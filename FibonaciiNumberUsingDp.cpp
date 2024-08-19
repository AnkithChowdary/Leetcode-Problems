class Solution {
public:
    // We use 1d array as only one value keeps changing
    int solutions[31];
    int solve(int n){
        if(n<=1){
           return n;
        }
        if(solutions[n]!=-1){
           return solutions[n];
        }
        return solutions[n]=solve(n-1)+solve(n-2);
    }
    int fib(int n) {
        if(n==1){
            return 1;
        }
        memset(solutions,-1,sizeof(solutions));
        return solve(n);
    }
};
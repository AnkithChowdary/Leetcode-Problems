class Solution {
  public:
      void primeHelper(int n, vector<bool>& v) {
      v[0] = v[1] = false;
      for (int i = 2; i <= sqrt(n); i++) {
          if (v[i]) {
              // Starts from i*i as others are already marked from 2 to i-1
              int j = i * i;
              while (j <= n) {
                  v[j] = false;
                  j += i;
              }
          }
      }
  }
  
      vector<int> closestPrimes(int left, int right) {
          vector<bool>isPrime(right+1,true);
          primeHelper(right,isPrime);
          vector<int>primes;
          for(int i=left;i<=right;i++){
              if(isPrime[i]==true){
                  primes.push_back(i);
              }
          }
  
          int minDiff=INT_MAX;
          vector<int>res(2,-1);
          for(int i=1;i<primes.size();i++){
              int diff=primes[i]-primes[i-1];
  
              if(diff<minDiff){
                  minDiff=diff;
                  res={primes[i-1],primes[i]};
              }
          }
  
          return res;
  
  
      }
  };
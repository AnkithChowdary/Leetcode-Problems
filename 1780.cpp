class Solution {
  public:
      bool checkPowersOfThree(int n) {
      
      // When we write ternary form of the given number we can fudn the answer
      while(n>0){
          if(n%3==2)
          return false;
          n/=3;
      }
      return true;
      }
  };

  class Solution {
    public:
        bool checkPowersOfThree(int n) {
            vector<int>vec;
    
            for(int i=0;i<n;i++){
                int powThree=pow(3,i);
                if(powThree>(INT_MAX)/3)
                break;
                vec.push_back(powThree);
    
            }
          // logy=xlog3
          //x=logy/log3
        
        for(int i=vec.size()-1;i>=0;i--){
            if(n>=vec[i])
            n=n-vec[i];
        } 
        return n==0;
        }
    };
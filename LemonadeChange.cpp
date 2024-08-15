class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
   
        int five=0;
        int ten= 0;

     
        for (int c: bills) {
            if (c==5) {
                five++;
            } else if (c==10) {
             
                if (five>0){
                    five--;
                    ten++;
                } else {
                    return false;
                }
            } else { 
               
                if (ten> 0 && five> 0) {
                    
                    five--;
                    ten--;
                } else if (five>=3) {
                    
                    five-=3;
                } else {
                   
                    return false;
                }
            }
        }
        // If we've made it through all customers, return true
        return true;
    }
};
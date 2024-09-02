class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        int ts=0;
        int n=chalk.size();
        for(int num:chalk){
            if(ts>k)
            break;
        ts+=num;
        }

        k=k%ts;
        
        for(int i=0;i<n;i++){
          
            if(k<chalk[i]){
                return i;
            }
            k=k-chalk[i];
        }
        return 0;

    }
};
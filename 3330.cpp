class Solution {
public:
    int possibleStringCount(string word) {
        int possibility=1; // She didn't make any mistake 
        int n=word.length();
        for(int i=1;i<n;i++){
            if(word[i]==word[i-1]){
                possibility++;
            }
        }

        return possibility;
    }
};
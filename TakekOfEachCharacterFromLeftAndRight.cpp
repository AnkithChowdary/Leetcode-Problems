class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.length();
        // Window abc 
        vector<int>win(3,0);
       
        vector<int>fq(3,0);
        // Count is needed
        for(int i=0;i<n;i++){
            fq[s[i]-'a']++;
        }


        for(int i=0;i<3;i++){
            if(fq[i]<k)
            return -1;
        }
         //aabaaaacaabc", k = 2  n=
        // fq = 8,2,2
        int left=0,maxLen=0,right=0;
        for(int right=0;right<n;right++){
            win[s[right]-'a']++;

            // Where the condition doesn't meet upto that point we discard  that part from window
                while(fq[0]-win[0]<k||fq[1]-win[1]<k||fq[2]-win[2]<k){
                   win[s[left]-'a']--;
                   left++; 
                }
                
            
            maxLen=max(maxLen,right-left+1);
        }
        return n-maxLen;


    }
};
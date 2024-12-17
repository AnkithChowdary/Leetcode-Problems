class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string ans;
        vector<int>freq(26, 0);
        for (char ch:s)
            freq[ch-'a']++;

        int last=25;

        while(last>=0){
            
            while(last>=0&&freq[last]==0)
                last--;

            if(last<0)
                break;

            char ch='a'+last;
            int count=min(freq[last],repeatLimit);

           
            ans.append(count,ch);
            freq[last]-=count;

           
            if(freq[last]>0){
                int j=last-1;

                
                while(j>=0 &&freq[j]==0)
                    j--;

                if (j<0)
                    break;

         
                ans.push_back('a'+j);
                freq[j]--;
            }
        }

        return ans;
    }
};

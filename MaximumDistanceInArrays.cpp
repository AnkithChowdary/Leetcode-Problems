class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
       
        int ans=0;

     
        int mini=arrays[0][0];
        // As the elements are in ascending order
        int maxi=arrays[0].back();
        
        for(int i=1;i<arrays.size();i++){
            // The difference of the last element of the array and the first element in second subarray
            ans=max(ans,abs(arrays[i].back()-mini));
            ans= max(ans,abs(maxi-arrays[i][0]));

            
            mini=min(mini,arrays[i][0]);
            maxi=max(maxi,arrays[i].back());
        }

        return ans;
    }
};

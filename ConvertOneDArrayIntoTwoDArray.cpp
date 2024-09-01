class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {

        if(m*n!=original.size()){
            vector<vector<int>>v(0,vector<int>(0));
            return v;
        }
        vector<vector<int>>v(m,vector<int>(n));

        int k=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                v[i][j]=original[k];
                k++;
            }
        }
        return v;
    }
};
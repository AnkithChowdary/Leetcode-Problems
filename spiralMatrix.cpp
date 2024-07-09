class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int startingRow=0;
        int endingCol=cols-1;
        int startingCol=0;
        int endingRow=rows-1;
        vector<int>v;
        int total=rows*cols;
        int count=0;
        while(count<total){
            for(int i=startingCol;i<=endingCol&&count<total;i++){
                v.push_back(matrix[startingRow][i]);
                count++;
            }
             startingRow++;
            for(int i=startingRow;i<=endingRow&&count<total;i++){
                v.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;
            for(int i=endingCol;i>=startingCol&&count<total;i--){
                v.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;
             for(int i=endingRow;i>=startingRow&&count<total;i--){
                v.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;

        }
        return v;
    }
};
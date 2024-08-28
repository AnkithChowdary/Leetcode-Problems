class Solution {
public:
    bool checkSub(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j){
        if(i<0||i>=grid1.size()||j<0||j>=grid1[0].size()){
            return true;
        }
        if(grid2[i][j]!=1){
            return true;
        }
        grid2[i][j]=-1;
        bool result=(grid1[i][j]==1);
        result=result&checkSub(grid1,grid2,i-1,j);  //Check Up
        result=result&checkSub(grid1,grid2,i+1,j);  //Bottom
        result=result&checkSub(grid1,grid2,i,j-1);  //Left
        result=result&checkSub(grid1,grid2,i,j+1);   //right
        return result;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int islands=0;
        int rows=grid2.size();
        int cols=grid2[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid2[i][j]==1&&checkSub(grid1,grid2,i,j)){
                    islands++;
                }
            }
        }
        return islands;
    }
};
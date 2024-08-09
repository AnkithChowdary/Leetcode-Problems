class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
       
      vector<int>v(10,0);               // Because for 9 it would be v[9]
        for(int i=row;i<row+3;i++) {       
            for(int j=col;j<col+3;j++) {
                 int n=grid[i][j];
                if(grid[i][j]<1||grid[i][j]>9||v[n]!=0){
                    return false;
                }
                v[n]=1;
            }
        }

       
        int sum1=grid[row][col]+grid[row][col+1]+grid[row][col+2];
        int sum2=grid[row+1][col]+grid[row+1][col+1]+grid[row+1][col+2];
        int sum3=grid[row+2][col]+grid[row+2][col+1]+grid[row+2][col+2];
        
        if(sum1!=15||sum2!=15||sum3!=15) return false;

        int colSum1=grid[row][col]+grid[row+1][col]+grid[row+2][col];
        int colSum2=grid[row][col+1]+grid[row+1][col+1]+grid[row+2][col+1];
        int colSum3 = grid[row][col+2]+grid[row+1][col+2] + grid[row+2][col+2];
        
        if(colSum1!=15||colSum2!=15||colSum3!=15) return false;

        int diagSum1=grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        int diagSum2=grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col];
        
        if(diagSum1!=15||diagSum2!=15) return false;

        return true;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int c=0;

      
        for (int i=0;i<=rows-3;i++) {      //There is no need to check at last as it doesn't form a 3x3 matrix
            for (int j=0;j<=cols-3;j++) {
                if(isMagicSquare(grid,i,j)) {
                    c++;
                }
            }
        }

        return c;
    }
};
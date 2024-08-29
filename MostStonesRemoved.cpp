class Solution {
public:
    void dfs(int stoneIndex,vector<vector<int>>&stones,vector<bool>&visited,unordered_map<int,vector<int>>& rows,unordered_map<int,vector<int>>&cols){
        visited[stoneIndex] = true;
        
        int x = stones[stoneIndex][0];
        int y = stones[stoneIndex][1];
        
        
        for (int neighbor : rows[x]) {
            if (!visited[neighbor]) {
                dfs(neighbor, stones, visited, rows, cols);
            }
        }
        for (int neighbor : cols[y]) {
            if (!visited[neighbor]) {
                dfs(neighbor, stones, visited, rows, cols);
            }
        }
    }

    

    int removeStones(vector<vector<int>>& stones) {
        int leftOverStones=0;
        int r=stones.size();
        int c=stones[0].size();
        unordered_map<int,vector<int>>rows,cols;
         for (int i = 0; i <r; i++) {
            rows[stones[i][0]].push_back(i);
            cols[stones[i][1]].push_back(i);
        }
        vector<bool>visited(r,false);
        for(int i=0;i<r;i++){
            if(!visited[i]){
           dfs(i,stones,visited,rows,cols);
               leftOverStones++;
            }
        }
          // Gives us th e number of stones that can be removed
        return r-leftOverStones;
    }
};
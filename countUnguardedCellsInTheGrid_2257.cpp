class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<vector<int>> directions = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}}; // west, north, south, east

        // Mark walls and guards
        for (auto& wall : walls) grid[wall[0]][wall[1]] = 1;
        for (auto& guard : guards) grid[guard[0]][guard[1]] = 2;

        
        auto dfs=[&](int x, int y, int dx, int dy) {
            while (x >= 0 && x < m && y >= 0 && y < n) {
                if (grid[x][y] == 1 || grid[x][y] == 2) break; 
                if (grid[x][y]==0)grid[x][y]=3;
                x += dx;
                y += dy;
            }
        };

        
        for (auto& guard : guards) {
            int x = guard[0], y = guard[1];
            for (auto& dir : directions) {
                dfs(x+dir[0],y+dir[1],dir[0],dir[1]);
            }
        }

       
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(grid[i][j] == 0) ++ans;
            }
        }
        
        return ans;
    }
};
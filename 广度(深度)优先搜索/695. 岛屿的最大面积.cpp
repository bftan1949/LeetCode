class Solution {
   public:
    int dfs(int i, int j, vector<vector<int>>& grid) {
        int size = 0;
        int positions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int x, y;

        if (flag[i][j] == 0) {
            size++;
            flag[i][j] = 1;
            for (int k = 0; k < 4; k++) {
                x = i + positions[k][0];
                y = j + positions[k][1];
                if (x < grid.size() && x >= 0 && y < grid[0].size() && y >= 0 && grid[x][y] == 1)
                    size += dfs(x, y, grid);
            }
            return size;
        } else
            return size;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int size = 0, maxSize = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && flag[i][j] == 0) {
                    size = dfs(i, j, grid);
                    if (size > maxSize)
                        maxSize = size;
                }
            }
        }
        return maxSize;
    }

   private:
    int flag[50][50] = {0};
};

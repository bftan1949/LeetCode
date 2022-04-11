// 广度优先搜索(超级源点)
class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int pos[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int row = grid.size(), col = grid[0].size();
        int x, y, count = 0, res = 0;
        queue<pair<int, int>> q;
        pair<int, int> node;
        vector<vector<int>> flag(row, vector<int>(col));
        vector<vector<int>> dist(row, vector<int>(col));
        // 先所有0点作为一个超级源点入队
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    q.emplace(i, j);
                    flag[i][j] = 1;
                }
                if (grid[i][j] == 1)
                    count++;
            }
        }

        while (!q.empty()) {
            node = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                y = node.first + pos[k][0];
                x = node.second + pos[k][1];
                if (y < row && y >= 0 && x < col && x >= 0 && !flag[y][x] && grid[y][x] == 1) {
                    q.emplace(y, x);
                    dist[y][x] = dist[node.first][node.second] + 1;
                    res = dist[y][x];
                    flag[y][x] = 1;
                    count--;
                }
            }
        }
        return count ? -1 : res;
    }
};

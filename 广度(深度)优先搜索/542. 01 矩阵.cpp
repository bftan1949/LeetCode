// 深度优先搜索 (暴力, 超时)
class Solution {
   public:
    int bfs(vector<vector<int>>& mat, vector<vector<int>> flag, int i, int j, int m, int n) {
        if (mat[i][j] != 0) {
            int pos[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            int x, y, dist = 0, best = 0xfffffff;
            flag[i][j] = 1;
            for (int k = 0; k < 4; k++) {
                dist = 0;
                x = i + pos[k][0];
                y = j + pos[k][1];
                if (x < m && x >= 0 && y < n && y >= 0 && flag[x][y] == 0) {
                    dist = bfs(mat, flag, x, y, m, n) + 1;
                    if (dist < best)
                        best = dist;
                }
            }
            return best;
        } else {
            return 0;
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n));
        vector<vector<int>> flag(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1)
                    dist[i][j] = bfs(mat, flag, i, j, m, n);
                else
                    dist[i][j] = 0;
            }
        }
        return dist;
    }
};

// 广度优先搜索(超级源点)
class Solution {
   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        pair<int, int> node;
        int pos[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int row = mat.size(), col = mat[0].size(), x, y;
        vector<vector<int>> flag(row, vector<int>(col));
        vector<vector<int>> dist(row, vector<int>(col));
        // 先所有0点作为一个超级源点入队
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 0) {
                    q.emplace(i, j);
                    flag[i][j] = 1;
                }
            }
        }

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                y = i + pos[k][0];
                x = j + pos[k][1];
                if (y < row && y >= 0 && x < col && x >= 0 && !flag[y][x]) {
                    q.emplace(y, x);
                    dist[y][x] = dist[i][j] + 1;
                    flag[y][x] = 1;
                }
            }
        }
        return dist;
    }
};

// 动态规划 (待续)




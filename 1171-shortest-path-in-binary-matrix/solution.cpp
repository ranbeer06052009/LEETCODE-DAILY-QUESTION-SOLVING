class Solution {
public:
    int row[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int col[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    bool valid(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1) {
            return -1;
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int steps = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if (i == n - 1 && j == n - 1) {
                    return steps + 1;
                }

                for (int k = 0; k < 8; k++) {
                    int new_i = i + row[k];
                    int new_j = j + col[k];

                    if (valid(new_i, new_j, n) && grid[new_i][new_j] == 0) {

                        grid[new_i][new_j] = 1;
                        q.push({new_i, new_j});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

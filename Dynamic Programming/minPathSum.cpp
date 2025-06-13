//Q.- Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.


class Solution {
public:
    int rec(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& memo) {
        if (m == 0 && n == 0) return grid[0][0];
        if (m < 0 || n < 0) return INT_MAX;
        if (memo[m][n] != -1) return memo[m][n];
        int up = rec(m - 1, n, grid, memo);
        int left = rec(m, n - 1, grid, memo);
        memo[m][n] = grid[m][n] + min(up, left);
        return memo[m][n];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return rec(m-1, n-1, grid, memo);
    }
};

//Q.- Given a triangle array, return the minimum path sum from top to bottom.
// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Solution - Use variable ending DP, start from top and explore all possible paths till you hit base case

class Solution {
public:
    int rec(int m, int n, vector<vector<int>>& triangle, vector<vector<int>> &dp) {
        if (m == triangle.size() - 1) return triangle[m][n];  // Base case: last row
        if (dp[m][n] != -1) return dp[m][n];                  // Memoized result
        int down = triangle[m][n] + rec(m + 1, n, triangle, dp);      // Move down
        int diag = triangle[m][n] + rec(m + 1, n + 1, triangle, dp);  // Move diagonal
        dp[m][n] = min(down, diag);
        return dp[m][n];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));  // Initialize dp table with -1
        return rec(0, 0, triangle, dp);                 // Start from top (0,0)
    }
};

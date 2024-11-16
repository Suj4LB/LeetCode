/* Also known as Grid Traveller problem in other places, this is the Unique Paths question in LeetCode
I had previously made the recursive code for this problem and now I have solved this using Dynamic Programing (Memoization) in this approach.

Q.- There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109.

*/

Solution - Keeping in mind of the steps of Memoization in Dynamic Programming, I have used a 2D Integer Vector for this solution.

class Solution {
public:
    int gridTravelMemo(int m, int n, vector<vector<int>> &memo) {
        // When both the row and column is 1, we get a solution which is 1
        if (n == 1 || m == 1) {
            memo[m][n] = 1;
            return 1;
        }
        if (n == 0 || m == 0) return 0; // Handling base case of either the row becoming 0 or the column becoming 0 ( Such grid doesn't exist therefore the solution is 0 )
        if (memo[m][n] == 0) // // If we don't have a solution, we compute it and store it and later return it
            memo[m][n] = gridTravelMemo(m - 1, n, memo) + gridTravelMemo(m, n - 1, memo);
        return memo[m][n]; // Returning the computed solution
    }
    
    int uniquePaths(int m, int n) {
        // Recursive Code - 
            // if(n<0 || m<0) return -1;
            // if(n == 0 || m ==0) return 0;
            // if(n==1 && m==1) return 1;
            // return (uniquePaths(n-1,m)) + uniquePaths(n,m-1);
        
        // Memoization Code Starts
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0)); // Memoization data structure with intial values as 0
        // These are the base cases for preventing the code to enter into the recursive function for such test cases - 
        if (m == 0 || n == 0) return 0; 
        if (m == 1 && n == 1) return 1;
        // Inserting the known solution (i.e, The solution is available only for 1 x 1 matrix which is 1)
        memo[1][1] = 1;
        // Calling the recursive function
        return gridTravelMemo(m, n, memo);
    }
};

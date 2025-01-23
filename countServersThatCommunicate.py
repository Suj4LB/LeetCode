#Q.- You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. 
#Two servers are said to communicate if they are on the same row or on the same column.
# Return the number of servers that communicate with any other server.

Solution - Simple Pre-Computing of number of servers in each row and column (if they are greater than 1 for each server, then it can communicate so we will add it in the result). Solved in Python because c++ hates me.

class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])
        row_count = [0] * ROWS
        col_count = [0] * COLS

        for r in range(ROWS):
            for c in range(COLS):
                if(grid[r][c]):
                    row_count[r] += 1
                    col_count[c] += 1

        res = 0
        for r in range(ROWS):
            for c in range(COLS):
                if(grid[r][c] and max(row_count[r], col_count[c]) > 1):
                    res+=1
        return res

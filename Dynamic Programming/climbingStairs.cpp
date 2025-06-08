// Q.- You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Recursive Code - 

class Solution {
public:
    int rec(int x)
    {
        if (x == 0 || x == 1) return 1;       
        int l = rec(x - 1);
        int r = rec(x - 2);
        return l + r;
    }

    int climbStairs(int n) {
        return rec(n);
    }
};


Memoized Code - 

class Solution {
public:
    int rec(int x, vector<int> &dp)
    {
        if (x == 0 || x == 1) return 1;
        if (dp[x] != -1) return dp[x];     
        int l = rec(x - 1, dp);
        int r = rec(x - 2, dp);
        return dp[x] = l + r;
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);   
        return rec(n, dp);
    }
};

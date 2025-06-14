//Q. - You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
// the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.


Solution - Pick and Notpick method of recursion.

Memoization Code -     
    
class Solution {
public:
    int solverec(vector<int>& nums, vector<int>& dp, int index)
    {
        if(index == 0) return nums[0];
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];
        int pick = nums[index] + solverec(nums, dp, index - 2);
        int notpick = 0 + solverec(nums, dp, index - 1);
        dp[index] = max(pick, notpick);
        return dp[index];
    }

    int rob(vector<int>& nums) {    
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solverec(nums, dp, n - 1);
    }
};



Tabulation Code - 

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n, 0);
        dp[0] = nums[0];
        for(int i = 1; i < n; ++i)
        {
            int take = nums[i]; if(i > 1) take += dp[i - 2];
            int notTake = 0 + dp[i - 1];
            dp[i] = max(take, notTake);
        }
        return dp[n - 1];
    }
};



Space Optimized Tabulation - 


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for(int i = 1; i < n; ++i)
        {
            int take = nums[i]; if(i > 1) take += prev2;
            int notTake = 0 + prev;
            int curr_i = max(take, notTake);
            prev2 = prev;
            prev = curr_i;
        }
        return prev;
    }
};

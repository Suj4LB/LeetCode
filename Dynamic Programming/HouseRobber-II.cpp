//Q. - You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. 
// All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. 
// Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.


Solution - Same as the house robber. First leave the last house and commpute the solution, then leave the last house and then compute the solution. 
          Finally return the maximum of these.

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int prev = nums[0];
        int prev2 = 0;
        for(int i = 1; i < n - 1; ++i)
        {
            int take = nums[i]; if(i > 1) take += prev2;
            int notTake = 0 + prev;
            int curr_i = max(take, notTake);
            prev2 = prev;
            prev = curr_i;
        }
        int first_ans = prev;
        prev = nums[1];
        prev2 = 0;
        for(int i = 2; i < n ; ++i)
        {
            int take = nums[i]; if(i > 1) take += prev2;
            int notTake = 0 + prev;
            int curr_i = max(take, notTake);
            prev2 = prev;
            prev = curr_i;
        }
        int sec_ans = prev;
        return max(first_ans, sec_ans);
    }
};

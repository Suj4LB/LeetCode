//Q.- Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.


Used a dynamic sliding window approach.

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int def = INT_MAX;
        int minWindow = def;
        int curr = 0;
        int left = 0;
        for(int right = 0; right < n; ++right){
            curr += nums[right];
            while(curr >= target){
                minWindow = min(minWindow, right - left + 1);
                curr -= nums[left];
                left++;
            }
        }
        if(minWindow == def) return 0;
        return minWindow;
    }
};

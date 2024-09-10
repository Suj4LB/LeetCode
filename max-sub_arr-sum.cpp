//Q.- Given an integer array nums, find the subarray with the largest sum, and return its sum.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxi = LONG_MIN; 
        long long sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum > maxi) {
                maxi = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxi;
    }
};

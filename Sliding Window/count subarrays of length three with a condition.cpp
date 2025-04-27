//Q. - Count Subarrays of Length Three With a Condition
// Given an integer array nums, return the number of subarrays of length 3 such that the sum of the first and third numbers equals exactly half of the second number.

 class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int counter = 0;
        for (int i = 0; i < n - 2; ++i) {
            if (2 * (nums[i] + nums[i+2]) == nums[i+1] ) {
                counter++;
            }
        }
        return counter;
    }
};

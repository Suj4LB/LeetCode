//Q. - Given an integer array nums, find the subarray with the largest sum, and return its sum.



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curr = 0; int maxi = INT_MIN;
        for(int i = 0; i < n; ++i){
            curr += nums[i];
            if(curr > maxi) maxi = curr;
            if(curr < 0) curr = 0;
        }
        return maxi;
    }
};

//Q . - You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

// The length of the subarray is k, and
// All the elements of the subarray are distinct.
// Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.



Used a hashmap instead of hashset

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;
        long long curr = 0; long long maxi = 0; int l = 0;
        for(int i = 0; i < n; ++i){
            curr += nums[i];
            count[nums[i]]++;
            if( i - l + 1 > k){
                count[nums[l]]--;
                if(count[nums[l]] == 0) count.erase(nums[l]);
                curr -= nums[l];
                l++;
            }
            if(i - l + 1 == k && count.size() == k){
                maxi = max(maxi, curr);
            }
        }
        return maxi;
    }
};

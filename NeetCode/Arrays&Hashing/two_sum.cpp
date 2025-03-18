//Q - Given an array of integers nums and an integer target, return the indices i and j such that nums[i] + nums[j] == target and i != j.
// You may assume that every input has exactly one pair of indices i and j that satisfy the condition.
// Return the answer with the smaller index first.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> hashMp;
        for(int i = 0; i < n; ++i)
        {
            hashMp[nums[i]] = i;
        }
        // vector<int> ans;
        for(int i = 0; i < n; ++i)
        {
            int diff = target - nums[i];
            if(hashMp[diff] > 0 && hashMp[diff] != i) return{i, hashMp[diff]};
        }
        return {};
    }
};

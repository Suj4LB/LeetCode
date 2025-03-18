//Q - Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto i: nums)
        {
            mpp[i]++;
        }
        for(auto n: mpp)
        {
            if(n.second > 1) return true;
        }
        return false;
    }
};

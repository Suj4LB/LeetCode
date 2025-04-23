//Q.- You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
// Return true if you can reach the last index, or false otherwise

Solution - BE GREEDY GREEDY GREEDY !!!

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIndex = 0;
        for(int i = 0; i < n; ++i)
        {
            if(i > maxIndex) return false;    //max index you can reach is not the last index so break it right there 
            maxIndex = max(maxIndex, i + nums[i]);
        }
        return true;
    }
};

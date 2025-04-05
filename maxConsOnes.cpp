//Q. - Given a binary array nums, return the maximum number of consecutive 1's in the array.

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int current = 0; int maxi = 0;
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] == 1) {
                current++; 
                maxi = max(maxi, current);
            }
            else current = 0;
        }
        return maxi;
    }
};

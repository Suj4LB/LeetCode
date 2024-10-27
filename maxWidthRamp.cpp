//Q. - A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.
// Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.


class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int>rightmax(n);
        rightmax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--){
            rightmax[i] = max(rightmax[i + 1], nums[i]);
        }
        int i=0,j=0,maxim=0;
        while(j<n){
            while(j<n && nums[i]<=rightmax[j]){
                j++;
            }
            maxim = max(maxim,j-i-1);
            i++;
            j = i + maxim + 1;
        }
        return maxim;
    }
};

//Q.- Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) cnt0++;
            else if (nums[i] == 1) cnt1++;
            else cnt2++;
        }

        for (int i = 0; i < cnt0; i++) nums[i] = 0; // replacing 0's

        for (int i = cnt0; i < cnt0 + cnt1; i++) nums[i] = 1; // replacing 1's

        for (int i = cnt0 + cnt1; i < n; i++) nums[i] = 2; 
        }
};

/*
Q.- Given an integer array nums, return the length of the longest strictly increasing subsequence.
*/

Solution - Use of Dynamic Programming. 
           I used the result of previous elements to find the result of the current element.

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n);
        lis[0] = 1;
        for (int i = 1; i < n; i++) {
            lis[i] = 1;
            for (int j = 0; j < i; j++) 
            if (nums[i] > nums[j] && lis[i] < lis[j] + 1) lis[i] = lis[j] + 1;
        }
        return *max_element(lis.begin(), lis.end());
    }
};

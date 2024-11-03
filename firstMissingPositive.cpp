/*
Q. - Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
     You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
*/

Solution - A Leetcode Hard problem, done it in O(n * logn) instead of n.

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int smallest = 1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;++i){
            if(nums[i]<1) continue;
            if(nums[i] == smallest) smallest++;
        }
        return smallest;
    }
};

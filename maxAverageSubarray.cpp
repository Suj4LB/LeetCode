/*
Q.- You are given an integer array nums consisting of n elements, and an integer k.
Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.
*/

Solution - Sliding window approach

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double avg = 0;
        double sum = 0;
        for(int i=0;i<k;++i){
            sum+=nums[i];
        }
        avg = sum/k;
        double curr = 0;
        for(int i=k;i<n;++i){
            sum-=nums[i-k]; // First element removed from the window
            sum+=nums[i];  // New element added to the window 
            curr = sum/k;  // Current average 
            if(curr>avg) avg = curr; // Maximum average 
        }
        return avg;
    }
};

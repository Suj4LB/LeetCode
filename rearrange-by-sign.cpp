//Q.- You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
// You should return the array of nums such that the the array follows the given conditions:
// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int pos=0,neg=1;
        for(int i=0;i<n;++i){
            if(nums[i]>0){
                ans[pos] = nums[i];
                pos+=2;
            }
            else{
                ans[neg] = nums[i];
                neg+=2;
            }
        }
        return ans;
    }
};

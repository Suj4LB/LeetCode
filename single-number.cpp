//Q.- Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor1 = 0;
        int n=nums.size();
        for(int i=0;i<n;++i){
            xor1=xor1^nums[i];
        }
        return xor1;
    }
};

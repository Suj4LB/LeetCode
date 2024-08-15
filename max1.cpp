//Q.- Given a binary array nums, return the maximum number of consecutive 1's in the array.
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxim=0,count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
                maxim = max(maxim,count);
            }
            else{
                count=0;
            }
        }
        return maxim;
    }
};

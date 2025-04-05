// Q.- Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int right = 0; int curr = 0; int left = 0;int maxi = 0; int countZero = 0;
        while(right < n){
            if(nums[right] == 0) countZero++;
            while(countZero > k){
                if(nums[left] == 0) countZero--;
                left++;
            }
            if(countZero <= k){
                curr = right - left + 1;
                maxi = max(maxi, curr);
            }
            right++;
        }
        return maxi;
    }
};

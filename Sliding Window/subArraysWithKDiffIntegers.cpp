//Q. - Given an integer array nums and an integer k, return the number of good subarrays of nums.
// A good array is an array where the number of different integers in that array is exactly k.
// For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.

Used a sliding window and hashmap with a simple concept of mathematics - 
Calculate the number of subarrays with ≤ k distinct numbers using the helper function.
Calculate the number of subarrays with ≤ k-1 distinct numbers using the same helper.
Subtract the two counts to get the number of subarrays with exactly k distinct numbers.

class Solution {
public:
    int helperFunc(vector<int>& nums, int k)
    {
        if(k < 0) return 0;
        int n = nums.size();
        int left = 0; int right = 0;
        int counter = 0; 
        unordered_map<int,int> hash;
        while(right < n)
        {
            hash[nums[right]]++;
            while(hash.size() > k)
            {
                hash[nums[left]]--;
                if(hash[nums[left]] == 0) hash.erase(nums[left]);
                left++;
            }
            counter += right - left + 1;
            right++;
        }
        return counter;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helperFunc(nums, k) - helperFunc(nums, k - 1);
    }
};

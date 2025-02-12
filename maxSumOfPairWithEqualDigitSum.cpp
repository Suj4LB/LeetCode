//Q.- You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].
// Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.

Solution - Hashing of the sum of the digits

class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        int x = n;
        while (x > 0) {   
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = -1;
        unordered_map<int, int> digitSumMap; 

        for (int num : nums) {
            int sum = digitSum(num);
            if (digitSumMap.count(sum)) {
                maxSum = max(maxSum, digitSumMap[sum] + num);
            }
            digitSumMap[sum] = max(digitSumMap[sum], num);
        }

        return maxSum;
    }
};

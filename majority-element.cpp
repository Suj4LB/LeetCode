// Q.- Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        for (auto it : mpp) {
            if (it.second > (n / 2)) {
                return it.first;
            }
        }

        return -1;
    }
};

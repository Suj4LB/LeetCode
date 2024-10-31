/*
Q. - You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.

In one operation:

choose an index i such that 0 <= i < nums.length,
increase your score by nums[i], and
replace nums[i] with ceil(nums[i] / 3).
Return the maximum possible score you can attain after applying exactly k operations.
The ceiling function ceil(val) is the least integer greater than or equal to val.
*/

Solution - Implement a max heap using a priority queue - 

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq(nums.begin(), nums.end());
        long long score = 0;
        while (k--){
            long long topEle = pq.top();
            pq.pop();
            score += topEle;
            long long nextVal = (topEle+2)/3;
            pq.push(nextVal);
        }
        return score;
    }
};

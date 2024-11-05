/*
Q. - You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete
*/

Solution - 

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> ans(nums.size());
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) m[nums[i]] = i;
        int rank = 1;
        for (auto it = m.rbegin(); it != m.rend(); it++) {
            if (rank == 1) ans[it->second] = "Gold Medal";
            else if (rank == 2) ans[it->second] = "Silver Medal";
            else if (rank == 3) ans[it->second] = "Bronze Medal";
            else ans[it->second] = to_string(rank);
            rank++;
        }
        return ans;
    }
};

/*
Q. - You are given m arrays, where each array is sorted in ascending order.

You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.
*/

Solution - Logical

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int mini = arrays[0][0];
        int maxi = arrays[0].back();
        int result = 0;
        for(int i = 1; i < n; ++i) {
            result = max(result, abs(arrays[i].back() - mini));
            result = max(result, abs(maxi - arrays[i][0]));
            mini = min(mini, arrays[i][0]);
            maxi = max(maxi, arrays[i].back());
        }
        return result;
    }
};

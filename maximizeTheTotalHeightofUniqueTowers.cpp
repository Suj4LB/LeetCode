/*
Q.- You are given an array maximumHeight, where maximumHeight[i] denotes the maximum height the ith tower can be assigned.

Your task is to assign a height to each tower so that:
The height of the ith tower is a positive integer and does not exceed maximumHeight[i].
No two towers have the same height.
Return the maximum possible total sum of the tower heights. If it's not possible to assign heights, return -1.
*/

Solution - Sort the towers first then traverse from end.

class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(), maximumHeight.end());
        int n = maximumHeight.size();
        long long sum = 0;
        long long currentHeight = maximumHeight[n - 1]; 
        for (int i = n - 1; i >= 0; --i) {
            if (currentHeight > maximumHeight[i]) {
                currentHeight = maximumHeight[i];
            }
            if (currentHeight <= 0) {
                return -1;
            }
            sum += currentHeight;
            currentHeight--;
        }
        return sum;
    }
};

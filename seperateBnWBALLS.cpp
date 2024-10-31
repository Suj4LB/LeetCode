/* 
Q. - There are n balls on a table, each ball has a color black or white.

You are given a 0-indexed binary string s of length n, where 1 and 0 represent black and white balls, respectively.

In each step, you can choose two adjacent balls and swap them.

Return the minimum number of steps to group all the black balls to the right and all the white balls to the left.

*/

Solution - Pretty simple and logical

class Solution {
public:
    long long minimumSteps(string s) {
        long long swap = 0;
        int black = 0; 
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') swap += (long long) black; 
            else black++; 
        }
        return swap;
    }
};

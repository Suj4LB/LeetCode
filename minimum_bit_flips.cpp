// Q. - A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.
// For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and flip it. We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.
// Given two integers start and goal, return the minimum number of bit flips to convert start to goal.


// Approach - 
//Converted both the decimal integers into binary equivalent and then stored them in two different arrays.
// Ran a loop of the array size and the count of different elements will return the minimum steps required to make them equal.

class Solution {
public:
    int minBitFlips(int start, int goal) {
        vector<long long> binaryNum(32,0);  
        vector<long long> ansNum(32,0);   
        int i = 0;
        while (start>0) {
            binaryNum[i] = (long long)start%2;
            start = start/2;
            i++;
        }
        int j = 0;
        while (goal>0) {
            ansNum[j] = (long long)goal%2;
            goal = goal/2;
            j++;
        }
        int count = 0;
        for (int k = 0;k<32;++k) {
            if (binaryNum[k] != ansNum[k]) count++;
        }
        return count;
    }
};

//Q. - The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer num, return its complement.

class Solution {
public:
    int findComplement(int num) {
        int decimalNumber = 0;
        int i = 0;
        while(num > 0) {
            int lastBit = num % 2;
            int complementBit = lastBit == 0 ? 1 : 0;
            decimalNumber += complementBit * pow(2, i);
            num = num / 2;
            i++;
        }
        return decimalNumber;
    }
};

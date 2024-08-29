//Q. - Given an integer x, return true if x is a palindrome, and false otherwise.

//Implemented the solution using stack data structure and mathematical logic.
//The order of digits would remain the same for all palindrome numbers.
//Extracted the digits using mathematics and rebuilded the reverse order of digits into a number and then we check if they are same or not.
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false; 
        if (x == 0) return true; 
        if (x % 10 == 0) return false;

        stack<long int> st;
        long int original = x;
        while (x > 0) {
            st.push(x % 10);
            x /= 10;
        }

        long int reconstructed = 0;
        long int multiplier = 1;

        while (!st.empty()) {
            reconstructed += st.top() * multiplier;
            st.pop();
            multiplier *= 10;
        }
        return original == reconstructed;
    }
};

/*
Q.-The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

*/

Solution - This solution is pretty basic for understading Dynamic Programming. I used memoization for hashing/storing recursive calls and then generated my answers with the help of the base case and recurrence relation.

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n; // Handling the base cases
        int memo[n+1]; // The array size should be n+1
        fill(memo, memo + (n + 1), -1); // Initialize all the elements of the memoization array as -1 {we don't know the solution yet}
        // Fill the known solutions first
        memo[0] = 0;
        memo[1] = 1;
        if (memo[n] != -1) return memo[n]; // If the solution exists, return it
        memo[n] = fib(n - 2) + fib(n - 1); // Otherwise, compute and store the solution ( This is memoization )
        return memo[n]; // Finally return the value of the Nth term
    }
};

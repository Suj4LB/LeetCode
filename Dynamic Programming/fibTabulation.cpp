/*
Q.- The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).
*/

Solution - I have used the bottom-up approach also known as Tabulation or Backtracking. This is super simple example but it gives an idea of how Tabulation works in Dynamic Programming.
           In tabulation, we form the answers based on some known solution and the recurrence relation. It is much preferred as it provides solution for every values unlike memoization.

class Solution {
public:
    int fib(int n) {
        // Using tabulation (backtracking/ bottom-up approach)
        if(n <= 1) return n; // Handling base cases
        int fib[n+1]; // Array will be of length N+1
        // Filling out our known solutions
        fib[0] = 0;
        fib[1] = 1;
        // Loop starts from 2 as we have filled the first two elements
        for(int i = 2; i<=n ; ++i)
        {
            fib[i] = fib[i-2] + fib[i-1]; // This is the recurrence relation of the fibonacci series, and we build the new solution with the help of the previous ones
        }
        return fib[n]; // Finally return the Nth term value 
    }
};

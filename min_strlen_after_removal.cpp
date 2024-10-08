//Q.- You are given a string s consisting only of uppercase English letters.

// You can apply some operations to this string where, in one operation, you can remove any occurrence of one of the substrings "AB" or "CD" from s.

// Return the minimum possible length of the resulting string that you can obtain.

// Note that the string concatenates after removing the substring and could produce new "AB" or "CD" substrings.

//Solution - 
class Solution {
public:
    int minLength(string s) {
        stack<char> stack;
        int n = s.size();
        for (int i = 0;i<n;i++) {
            char c = s[i];
            if (stack.empty()) {
                stack.push(c);
                continue;
            }
            if (c == 'B' && stack.top() == 'A') {
                stack.pop();
            }
            else if (c == 'D' && stack.top() == 'C') {
                stack.pop();
            }
            else {
                stack.push(c);
            }
        }
        return stack.size();
    }
};

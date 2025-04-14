//Q. - You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
// Return the length of the longest substring containing the same letter you can get after performing the above operations.

Used sliding window and hashmap

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> hash;
        int left = 0;
        int maxLen = 0;
        int maxFreq = 0;
        for(int right = 0; right < n; ++right) {
            hash[s[right]]++; // Use the character directly as the key
            maxFreq = 0;
            for(auto const& [key, val] : hash) { 
                maxFreq = max(maxFreq, val);
            }
            while((right - left + 1) - maxFreq > k) {
                hash[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

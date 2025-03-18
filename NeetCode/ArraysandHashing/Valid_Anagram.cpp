//Q - Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.
// An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {    //Different length means there are different characters
            return false;
        }
        string sortedS = s;
        string sortedT = t;
        sort(sortedS.begin(), sortedS.end());
        sort(sortedT.begin(), sortedT.end());
        return sortedS == sortedT;
    }
};

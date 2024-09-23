//Q. - You are given an array of strings message and an array of strings bannedWords.
      // An array of words is considered spam if there are at least two words in it that exactly match any word in bannedWords.
      // Return true if the array message is spam, and false otherwise.


//Approach - Used an unordered set from c++ STL library to solve this problem

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> st(bannedWords.begin(), bannedWords.end());
        int cnt = 0;
        for(auto it : message) {
            if(st.find(it) != st.end()) cnt++;
        } 
        return (cnt >= 2);
    }
};

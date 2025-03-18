//Q- Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.
// An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        for(string s: strs){
            string x = s;
            sort(x.begin(), x.end());
            mpp[x].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto i: mpp){
            ans.push_back(i.second);
        }
        return ans;
    }
};

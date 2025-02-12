//Q.- Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// Solution - sorted word for all the anagrams will be the same, so we make the sorted word as the key and store all the corresponding words mapped to that key in a hashmap and then store them in the answer array and return it.

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

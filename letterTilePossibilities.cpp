// Q.- You have n  tiles, where each tile has one letter tiles[i] printed on it.
// Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

// Approach - Used hashing and backtracking using a tree structure for this problem. We keep count of the number of characters left and explore the possible characters that can be explored after choosing any one of the available characters(whose count is > 1).
// Better explained by neetcode - https://www.youtube.com/watch?v=8FrJX-P_DnE

class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> count;
        for (char c : tiles) {
            count[c]++;
        }
        return backtrack(count);
    }
    
    int backtrack(unordered_map<char, int>& count) {
        int res = 0;
        for (auto& [c, freq] : count) {
            if (freq > 0) {
                count[c]--;
                res += 1 + backtrack(count);
                count[c]++;
            }
        }
        return res;
    }
};


/*
Python code for the same - 
  class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        count = Counter(tiles)
        def backtrack():
            res = 0
            for c in count:
                if count[c] > 0:
                    count[c] -= 1
                    res += 1 
                    res += backtrack()
                    count[c] += 1
            return res
        return backtrack()
*/

/*
Q. - You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
*/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> ordered;
        for (size_t k = 0; k < nums.size(); ++k)
            for (auto n: nums[k]) ordered.push_back({n, k});

        sort(ordered.begin(), ordered.end());
        int i = 0, k = 0; 
        vector<int> ans;  
        unordered_map<int, int> mpp; 
        for (size_t j = 0; j < ordered.size(); ++j) {
            if(!mpp[ordered[j].second]++)++k;
            if(k == nums.size()) { 
                while(mpp[ordered[i].second] > 1) --mpp[ordered[i++].second]; 
                if(ans.empty() || ans[1] - ans[0] > ordered[j].first - ordered[i].first) {
                    ans = vector<int>{ordered[i].first, ordered[j].first};
                }
            }
        }
        return ans;  
    }
};

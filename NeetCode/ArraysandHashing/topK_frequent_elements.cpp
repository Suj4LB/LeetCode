//Q - Given an integer array nums and an integer k, return the k most frequent elements within the array.
// The test cases are generated such that the answer is always unique.
// You may return the output in any order.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int num: nums){
            mpp[num]++;
        }
        vector<pair<int, int>> arr;
        for (const auto& p : mpp) {
            arr.push_back({p.second, p.first});
        }
        sort(arr.rbegin(), arr.rend());
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};

/*
Q.- You are given a 2D integer array intervals where intervals[i] = [lefti, righti] represents the inclusive interval [lefti, righti].

You have to divide the intervals into one or more groups such that each interval is in exactly one group, and no two intervals that are in the same group intersect each other.

Return the minimum number of groups you need to make.

Two intervals intersect if there is at least one common number between them. For example, the intervals [1, 5] and [5, 8] intersect.
*/

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int, int>>ans;
        for(int i=0; i<intervals.size(); i++){
            ans.push_back({intervals[i][0], 1}); 
            ans.push_back({intervals[i][1] + 1, -1});  
        }
        sort(ans.begin(), ans.end());
        
        int maxi = 1;
        int cnt = 0;
        
        for(auto it: ans){
            int type = it.second;
            cnt += type;
            maxi = max(maxi, cnt);
        }
        
        return maxi;
    }
};

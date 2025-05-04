//Q. - Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
// Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

Solution - Sort the intervals array based on the end time [i][1] (the second element basically), and then compare and count which intervals need to be removed.

bool cmp(vector<int>& a, vector<int>& b) {return a[1] < b[1];} 

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 0; 
        int start = intervals[0][0],end = intervals[0][1]; 
        for(int i = 1; i < n; i++){ 
            if(intervals[i][0] < end){ 
                ans++; 
            } 
            else if(intervals[i][0] >= end){  
                start = intervals[i][0]; 
                end = intervals[i][1]; 
            }
        }
        return ans;
    }   
};

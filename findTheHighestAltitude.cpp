/*
Q.- There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point. 
*/

Solution - Use of pre-computation using hashmap
  
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        map<int,int> mpp;
        mpp[0] = 0;
        int n = gain.size();
        for(int i=1;i<=n;++i){
            mpp[i] = mpp[i-1]+gain[i-1];
        }
        int max_value = INT_MIN;
        for (const auto& pair : mpp) {
            if (pair.second > max_value) {
                max_value = pair.second;
            }
        }
        return max_value;
    }
};

//Q.- You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

// One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

// Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

// Note: You cannot rotate an envelope.

// Solution - 
class Solution {
public:
    static bool comp(vector<int> &a , vector<int> &b){
        if(a[0] == b[0]){
            return a[1]>b[1];
        }
        else{
            return a[0]<b[0];
        }
        return false;
    }
    int maxEnvelopes(vector<vector<int>>& en) {
        sort(en.begin(), en.end(),comp);
        vector<int> ans;
        ans.push_back(en[0][1]);
        for(int i=0; i<en.size(); i++) {
            if(en[i][1] > ans.back()) ans.push_back(en[i][1]);
            else{
                int index = lower_bound(ans.begin(), ans.end(), en[i][1]) - ans.begin();
                ans[index] = en[i][1];
            }
        }
        return ans.size();
    }
};

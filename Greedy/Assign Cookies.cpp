//Q. - Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. 
// Your goal is to maximize the number of your content children and output the maximum number.

Approach - Sort and be "greedy"

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int left = 0; int right = 0; int counter = 0;
        while(right < s.size() && left < g.size()){
            if(g[left] <= s[right]){
                counter++;
                right++;
                left++;
            }
            else right++;
        }
        return counter;
    }
};

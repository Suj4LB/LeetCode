//Q.-  Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expSum = (n*(n+1))/2;
        int realSum = 0;
        for(int i=0;i<n;++i){
            realSum = realSum+nums[i];
        }
        return (expSum-realSum);
    }
};

//the solution can also be implemented by using XOR operation on each array element.

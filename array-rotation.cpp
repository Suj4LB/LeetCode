//Q.- Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0 || n==1 || k==n) ;
        else{
            k=k%n;
            int temp[k];
            int j=0;
            for(int i=n-k;i<n;++i){
                temp[j] = nums[i];
                j++;
            }
            for(int i=n-1;i>=k;--i){
                nums[i]=nums[i-k];
            }
            for(int i=0;i<k;++i){
                nums[i] = temp[i];
            }
        }
    }
};

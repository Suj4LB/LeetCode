// Q. - You are given an array of integers arr[]. Your task is to reverse the given array.
// Note: Modify the array in place

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int n = arr.size();
        for(int i = 0; i < n / 2; ++i){
            swap(arr[i], arr[n - i - 1]);
        }
    }
};

//Q. - There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
// Your score is the sum of the points of the cards you have taken.
// Given the integer array cardPoints and the integer k, return the maximum score you can obtai

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        if (k == n) return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int sumFront = 0; int sumBack = 0; int maxSum = 0;
        for(int i = 0; i < k; ++i)
        {
            sumFront += cardPoints[i];
        }
        maxSum = sumFront;
        int right = n - 1;
        for(int i = k - 1; i >=0 ; --i)
        {
            sumFront -= cardPoints[i];
            sumBack += cardPoints[right];
            right--;
            maxSum = max(maxSum, sumFront + sumBack);
        }
        return maxSum;
    }
};

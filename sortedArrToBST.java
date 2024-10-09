//Q. - Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

Used the logic of Inorder trasversal. As the inorder traversal also gives us a sorted manner values, the middle or the mean value of the value range is generally the root node of the tree.
Using this, I have built the entire BST

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode createBST(int nums[], int l, int r){
        if (l > r) { 
            return null;
        }
        int rootData = l+(r-l)/2;
        TreeNode root = new TreeNode(nums[rootData]);
        root.left = createBST(nums,l,rootData-1);
        root.right = createBST(nums,rootData+1,r);
        return root;
    }
    public TreeNode sortedArrayToBST(int[] nums) {
        int n = nums.length;
        return createBST(nums, 0, n - 1);
    }
}

//Q.- Given the head of a singly linked list, reverse the list, and return the reversed list.

We have to implement this in such a way that the reversing is in in-place(i.e, we don't have to use some other data structure like stack or a temporary array/vector).
I used three pointers approach in this : 
  One pointer keeps track of the previous nodes and one keeps track of the the current node that we are on and the third one will be one node ahead of the current node.

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
  
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode current = head;
        while(current!=null){
            ListNode fast = current.next;
            current.next = prev;
            prev = current;
            current = fast;
        }
        return prev;
    }
}

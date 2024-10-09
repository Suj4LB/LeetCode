//Q. - Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

This problem is the same as the reversing a singly linked list problem, we just have to iterate over a specific index first and then apply the same reversing algortihm using three pointers.

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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if(head == null || left == right) return head;
        ListNode dummy = new ListNode(0); 
        dummy.next = head;
        ListNode prev = dummy; 
        for(int i = 0; i < left - 1; i++)
            prev = prev.next; 
        ListNode curr = prev.next; 
        for(int i = 0; i < right - left; i++){
            ListNode forw = curr.next; 
            curr.next = forw.next;
            forw.next = prev.next;
            prev.next = forw;
        }
        return dummy.next;
    }
}

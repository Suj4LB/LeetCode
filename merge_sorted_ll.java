//Q - You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dum;
    struct ListNode *temp = &dum;
    dum.next = NULL;
    while(list1!=NULL && list2!=NULL){
        if(list1->val<=list2->val){
            temp->next = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    if(list1!=NULL){
        temp->next = list1;
    }
    else{
        temp->next = list2;
    }
    return dum.next; 
}

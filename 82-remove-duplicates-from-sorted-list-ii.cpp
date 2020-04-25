/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head -> next == NULL) return head;
        if (head -> val == head -> next -> val) {
            while (head -> next && head -> val == head -> next -> val) {head -> next = head -> next -> next;}
            head = deleteDuplicates(head -> next);
        } else {head -> next = deleteDuplicates(head -> next);} 
        return head;
    }
};
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* new_ode = new ListNode(-1);
        ListNode* new_node = new_ode;
        int sum = 0;
        bool flag = false;
        while(l1 != NULL || l2 != NULL){
            sum = 0;
            if(l1 != NULL){
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2 != NULL){
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            if(flag) sum++;
            new_node -> next = new ListNode(sum % 10);
            new_node = new_node -> next;
            flag = sum / 10;
        }
        if(flag) new_node -> next = new ListNode(1);
        return new_ode -> next; 
    }
};
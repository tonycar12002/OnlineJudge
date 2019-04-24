/*
Author: Tony Hsiao
Date: 2019/04/24
Topic: 2. Add Two Numbers
Note: Linked-list加法題目
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
        ListNode* start = new ListNode(0);
		ListNode* now = new ListNode(0);
		ListNode* l3 = new ListNode(0);
        int carry = 0, sum;
        start = now;
        while(l1 != NULL && l2 != NULL){
        	sum = l1 -> val + l2 -> val + carry;
        	now->next = new ListNode(sum % 10);
        	carry = sum / 10;
        	now = now -> next;
        	l1 = l1 -> next;
        	l2 = l2 -> next;
        }
        l3 = (l1 == NULL) ? l2 : l1;
       	while(l3 != NULL){
       		sum = l3 -> val + carry;
       		now->next = new ListNode(sum % 10);
       		carry = sum / 10;
       		now = now -> next;
       		l3 = l3 -> next;
       	}
        if(carry != 0)
            now->next = new ListNode(1);
       	return start -> next;
    }
};








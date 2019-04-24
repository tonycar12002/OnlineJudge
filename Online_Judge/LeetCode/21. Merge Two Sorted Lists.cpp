/*
Author: Tony Hsiao
Date: 2019/04/24
Topic: 21. Merge Two Sorted Lists
Note: Basic Linked List 
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* start = new ListNode(0);
		ListNode* now = new ListNode(0);
        ListNode* l3 = new ListNode(0);
        start = now;
        while(l1 != NULL && l2 != NULL){
            if(l1 -> val > l2 -> val){
                now -> next = new ListNode(l2->val);
                l2 = l2 -> next;
            }
            else{
                now -> next = new ListNode(l1->val);
                l1 = l1 -> next;
            }
            now = now -> next;
        }
        l3 = (l1 == NULL) ? l2 : l1;
       	while(l3 != NULL){
       		now->next = new ListNode(l3 -> val);
       		now = now -> next;
       		l3 = l3 -> next;
       	}
       	return start -> next;
    }
};
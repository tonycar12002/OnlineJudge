/*
Author: Tony Hsiao
Date: 2019/05/06
Topic: 92. Reverse Linked List II
Note: Linked-List
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head->next)
            return head;
        ListNode *cur, *dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        for(int i=1;i<m;i++)
            head = head -> next;
        
        ListNode *tmp, *prev;
        prev = head->next;
        cur = prev->next;
        for(int i=m;i<n;i++){
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        head->next->next = cur;
        head->next = prev;
        
        return dummy->next;
    }
};
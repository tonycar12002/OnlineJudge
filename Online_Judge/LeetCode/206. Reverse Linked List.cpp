/*
Author: Tony Hsiao
Date: 2019/05/06
Topic: 206. Reverse Linked List
Note:
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
    ListNode* reverseList(ListNode* head) {
        ListNode* reverse = NULL, cur = head, *prev;
        while(cur){
            prev = cur;
            cur = cur->next;
            prev->next = reverse;
            reverse = prev;
            
        }
        return reverse;
    }
};
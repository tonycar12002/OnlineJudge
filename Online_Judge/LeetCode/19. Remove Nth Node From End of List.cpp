/*
Author: Tony Hsiao
Date: 2019/04/25
Topic: 19. Remove Nth Node From End of List
Note: Linked list
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* now = new ListNode(0);
        ListNode* record_last = new ListNode(0);
        int node_count = 1;
        now = head;
        while(now->next !=NULL){
            node_count ++;
            record_last = now;
            now = now -> next;
        }
        if(n == node_count){ // remove head
            head = head -> next;
        }
        else if(n == 1){ // remove last
            record_last -> next = NULL;
        }
        else{
            int target = node_count - n ;
            now = head;
            while(--target){
                now = now -> next;
            }
            now -> next = now -> next -> next;
        }
        return head;
    }
};
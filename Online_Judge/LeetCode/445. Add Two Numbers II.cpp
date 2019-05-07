/*
Author: Tony Hsiao
Date: 2019/05/07
Topic: 445. Add Two Numbers II
Speed: 20ms, 13.7MB
Note: 題目要求不可以reverse list
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
        stack<int> num1, num2;
        while(l1!=NULL){
            num1.push(l1->val);
            l1 = l1 -> next;
        }
        while(l2!=NULL){
            num2.push(l2->val);
            l2 = l2 -> next;
        }
        int carry = 0, tmp;
        ListNode* head, *prev = NULL;
        while(num1.size() && num2.size()){
            tmp = carry + num1.top() + num2.top();
            num1.pop();
            num2.pop();
            carry = tmp / 10;
            tmp = tmp % 10;
            head = new ListNode(tmp);
            head->next = prev;
            prev = head;
        }
        if(num1.size() == 0)
            num1 = num2;
        while(num1.size()){
            tmp = carry + num1.top();
            num1.pop();
            carry = tmp / 10;
            tmp = tmp % 10;
            head = new ListNode(tmp);
            head->next = prev;
            prev = head;
        }
        if(carry){
            head = new ListNode(1);
            head->next = prev;
            prev = head;
        }
        return head;
    }
};
/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (31.65%)
 * Likes:    5824
 * Dislikes: 1505
 * Total Accepted:    988.1K
 * Total Submissions: 3.1M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *final_head = new ListNode(0);
        ListNode *cur_final = final_head;
        int carry = 0;

        for(auto cur_l1 = l1,  cur_l2 = l2; cur_l1 != NULL || cur_l2 != NULL;cur_l1 = cur_l1 == NULL? NULL:cur_l1->next,cur_l2 = cur_l2 == NULL? NULL:cur_l2->next)
        {
            int v1 = cur_l1 == NULL? 0:cur_l1->val;
            int v2 = cur_l2 == NULL? 0:cur_l2->val;
            int sum = v1 + v2 + carry;  
            cur_final->next = new ListNode(sum % 10 );
            cur_final = cur_final->next;
            carry = sum > 9 ? 1 : 0;

        }
        
        cur_final ->next = carry ? new ListNode(1) : NULL;
        return final_head->next;
    }
};

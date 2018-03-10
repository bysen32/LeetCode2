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
        if (m >= n)
            return head;
        ListNode *cur = head;
        ListNode *pre = NULL;
        ListNode *next = head->next;
        ListNode *oldHeadLast = NULL;
        ListNode *oldTailFirst = NULL;
        ListNode *newHeadFirst = NULL;
        ListNode *newTailLast = NULL;
        int step = 0;
        while (cur != NULL) {
            step += 1;
            if (step == m - 1) {
                oldHeadLast = cur;
            }
            if (step == m) {
                newHeadFirst = cur;
            }
            if (step == n) {
                newTailLast = cur;
            }
            if (step == n + 1) {
                oldTailFirst = cur;
            }
            if (m <= step && step <= n) {
                next = cur->next;
                cur->next = pre;
                
                pre = cur;
                cur = next;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        if (oldHeadLast != NULL)
            oldHeadLast->next = newTailLast;
        else
            head = newTailLast;
        newHeadFirst->next = oldTailFirst;
        return head;
    }
};

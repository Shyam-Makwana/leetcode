/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev = new ListNode(0, head);
        ListNode *ans = prev;
        ListNode *cur = head;

        while(cur && cur->next) {
            while(cur->next && cur->val==cur->next->val)    cur = cur->next;
            if(prev->next == cur)   prev = prev->next;
            else    prev->next = cur->next;
            cur = cur->next;
            
        }
        return ans->next;
    }
};
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
    ListNode* getKth(ListNode *curr, int k){
        while(curr && k){
            curr = curr->next;
            k--;
        }
        return curr;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *groupPrev = dummy;
        while(true){
            ListNode *kth = getKth(groupPrev, k);
            if(!kth)    break;
            ListNode *groupNext = kth->next;
            
            ListNode *prev = kth->next, *curr = groupPrev->next, *tmp;
            while(curr!=groupNext){
                tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            tmp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = tmp;
        }
        return dummy->next;
    }
};
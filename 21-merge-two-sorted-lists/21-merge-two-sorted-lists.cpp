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
    ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
        ListNode* ans = new ListNode();
        ListNode* curr = ans;
        while(A && B){
            if(A->val < B->val){
                curr->next = A;
                A = A->next;
            }
            else{
                curr->next = B;
                B = B->next;
            }
            curr = curr->next;
        }
        curr->next = A ? A : B;
        return ans->next;
    }
};
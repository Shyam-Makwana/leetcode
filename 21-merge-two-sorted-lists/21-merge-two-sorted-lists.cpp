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
        ListNode *ans = new ListNode();
        ListNode *dummy = ans;
        while(A && B){
            if(A->val < B->val){
                dummy->next = A;
                A = A->next;
            }
            else{
                dummy->next = B;
                B = B->next;
            }
            dummy = dummy->next;
        }
        dummy->next = A ? A : B;
        return ans->next;
    }
};
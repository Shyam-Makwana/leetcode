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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())   return NULL;
        
        while(size(lists)>1){
            vector<ListNode*> mergedLists;
            for(int i=0;i<size(lists); i+=2){
                ListNode *l1 = lists[i];
                ListNode *l2 = ((i+1)<size(lists)) ? lists[i+1] : NULL;
                mergedLists.push_back(mergeTwoLists(l1, l2));
            }
            lists = mergedLists;
        }
        return lists[0];
    }
    
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
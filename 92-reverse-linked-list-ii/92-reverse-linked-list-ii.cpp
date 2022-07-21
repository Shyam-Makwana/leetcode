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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        // Move the two pointers until they reach the proper starting point in the list.
        ListNode *prev = NULL, *curr = head;
        int cnt = 1;
        while(cnt < left){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        
        // The two pointers that will fix the final connections.
        ListNode *con = prev, *tail = curr;
        
        // Iteratively reverse the nodes
        ListNode *tmp = NULL;
        while(cnt <= right){
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
            cnt++;
        }
        
        // If con == null means left == 1 or else left != 1
        // Join the con
        if(con)    con->next = prev;
        else head = prev;
        
        // Join the tail
        tail->next = curr;
        
        return head;
    }
};
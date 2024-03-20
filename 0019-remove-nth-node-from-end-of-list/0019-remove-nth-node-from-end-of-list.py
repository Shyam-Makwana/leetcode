# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        ans = ListNode(0, head)
        
        curr = head
        list_len = 0
        while curr:
            list_len += 1
            curr = curr.next
        
        list_len = list_len - n
        curr, dummy = head, ans
        while list_len > 0:
            curr = curr.next
            dummy = dummy.next
            list_len-=1
        
        # print(curr.val, dummy.val)
        dummy.next = curr.next
        return ans.next
        
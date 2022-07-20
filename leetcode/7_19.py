from curses.ascii import SO


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

            if slow == fast:
                p, q = head, slow
                while p != q:
                    p = p.next
                    q = q.next
                return p
        return None
    def swapPairs(self, head: ListNode) -> ListNode:
        dummy_h = ListNode(next=head)
        pre = dummy_h
        while pre.next and pre.next.next:
            cur = pre.next
            post = pre.next.next
            cur.next = post.next
            post.next = cur
            pre.next = post
            pre = cur
        return dummy_h.next

    def reverseList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        ret = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return ret
    def reverseList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        pre, cur = None, head
        while cur:
            nt = cur.next
            cur.next = pre
            pre = cur
            cur = nt
        return pre


so = Solution()
so.swapPairs(ListNode(1,ListNode(2,ListNode(3,ListNode(4)))))
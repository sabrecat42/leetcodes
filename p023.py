# Definition for singly-linked list.
from typing import List, Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def merge(self, left_list, right_list) -> Optional[ListNode]:
        # print("merging ", left_list, " with ", right_list)
        left_node = left_list
        right_node = right_list
        if left_node == None and right_node == None:
            return None
        if left_node == None and right_node != None:
            return right_node
        if left_node != None and right_node == None:
            return left_node
        mergedList = None
        if left_node.val < right_node.val:
            mergedList = 
            left_node = left_node.next
        else:
            mergedList = ListNode(val=right_node.val)
            right_node = right_node.next
        mergedListTail = mergedList
        while left_node != None and right_node != None:
            if left_node.val < right_node.val:
                mergedListTail.next = ListNode(val=left_node.val) # type: ignore
                mergedListTail = mergedListTail.next # type: ignore
                left_node = left_node.next
            else:
                mergedListTail.next = ListNode(val=right_node.val)
                mergedListTail = mergedListTail.next
                right_node = right_node.next
        if left_node != None:
            mergedListTail.next = left_node
        if right_node != None:
            mergedListTail.next = right_node
        return mergedList

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        match len(lists):
            case 0:
                return None
            case 1:
                return lists[0]
            case _ if len(lists) > 1: 
                mid_idx = len(lists) // 2
                left_lists = self.mergeKLists(lists[:mid_idx])
                right_lists = self.mergeKLists(lists[mid_idx:])
                return self.merge(left_list=left_lists, right_list=right_lists)

# ---------- helpers ----------

def build_list(values: List[int]) -> Optional[ListNode]:
    if not values:
        return None
    head = ListNode(values[0])
    curr = head
    for v in values[1:]:
        curr.next = ListNode(v)
        curr = curr.next
    return head


# def print_list(node: Optional[ListNode]):
    vals = []
    while node:
        vals.append(str(node.val))
        node = node.next
    print(" -> ".join(vals) if vals else "empty")


# ---------- main ----------

def main():
    test_cases = [
        # Test case 1
        [[1, 4, 5], [1, 3, 4], [2, 6]],

        # Test case 2
        [[0, 2, 2], [1, 3, 5, 7], [1, 1, 4], [6]],

        # Test case 3
        [[1, 2, 3, 4, 5]],

        # Test case 4
        [],

        # Test case 5
        [[], [1], [2, 3], []],

        # Test case 6
        [[], [], []],

        # Test case 7
        [[2, 2, 2], [2, 2], [2]],

        # Test case 8
        [[-10, -5, -2], [-6, -3, 0], [1, 4]],

        # Test case 9
        [[-8, -3, -1], [0], [2, 2, 3], [5, 9, 12]],
    ]

    sol = Solution()

    for i, tc in enumerate(test_cases, 1):
        print(f"\nTest Case {i}")
        lists = [build_list(lst) for lst in tc]
        result = sol.mergeKLists(lists)
        print_list(result)


if __name__ == "__main__":
    main()
package main

import (
	"slices"
)

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

// recursive function:
// check head of all llists and add the smallest one to mergedList as head. (optimization: if multiple head of lists share value -> add all)
// move head of selected list(s) to next node
// update lists and mergedList and call recursive method (aka goto 1st step)

func recMergeKLists(lists []*ListNode, mergedList *ListNode) *ListNode {
	if len(lists) == 0 { // escape condition
		// fmt.Println("no lists -> return")
		return mergedList
	}
	headVals := []int{}
	areListsEmpty := true
	for i := 0; i < len(lists); i++ {
		if lists[i] != nil {
			// fmt.Println("add to hadVals +=", lists[i].Val)
			headVals = append(headVals, lists[i].Val)
			areListsEmpty = false
		}
	}
	if areListsEmpty {
		// fmt.Println("all lists are empty -> return")
		return mergedList
	}
	minVal := slices.Min(headVals)
	// fmt.Println("extracted headVals=", headVals, "minVal=", minVal)
	for i := 0; i < len(lists); i++ {
		if lists[i] != nil && lists[i].Val == minVal {
			// fmt.Println("adding", minVal, "to mergedList")
			if mergedList == nil {
				mergedList = &ListNode{minVal, nil}
			} else {
				node := mergedList
				for {
					if node.Next == nil {
						node.Next = &ListNode{minVal, nil}
						break
					}
					// // fmt.Print(node.Val, " ")
					node = node.Next
				}
			}
			lists[i] = lists[i].Next
		}
	}
	return recMergeKLists(lists, mergedList)
}

func mergeKLists(lists []*ListNode) *ListNode {
	return recMergeKLists(lists, nil)
}

func main() {
	// lists := []*ListNode{
	// 	{Val: 1, Next: &ListNode{Val: 4, Next: &ListNode{Val: 5}}},
	// 	{Val: 1, Next: &ListNode{Val: 3, Next: &ListNode{Val: 4}}},
	// 	{Val: 2, Next: &ListNode{Val: 6}},
	// }
	// lists := []*ListNode{
	// 	{Val: 0, Next: &ListNode{Val: 2, Next: &ListNode{Val: 2}}},
	// 	{Val: 1, Next: &ListNode{Val: 3, Next: &ListNode{Val: 5, Next: &ListNode{Val: 7}}}},
	// 	{Val: 1, Next: &ListNode{Val: 1, Next: &ListNode{Val: 4}}},
	// 	{Val: 6},
	// }
	// lists := []*ListNode{
	// 	{Val: 1, Next: &ListNode{
	// 		Val: 2, Next: &ListNode{
	// 			Val: 3, Next: &ListNode{
	// 				Val: 4, Next: &ListNode{Val: 5},
	// 			},
	// 		},
	// 	}},
	// }
	// lists := []*ListNode{
	// 	nil,
	// 	{Val: 1},
	// 	{Val: 2, Next: &ListNode{Val: 3}},
	// 	nil,
	// }
	// lists := []*ListNode{
	// 	{Val: -1000, Next: &ListNode{
	// 		Val: -500, Next: &ListNode{
	// 			Val: 0, Next: &ListNode{Val: 500},
	// 		},
	// 	}},
	// 	{Val: 1, Next: &ListNode{
	// 		Val: 2, Next: &ListNode{
	// 			Val: 3, Next: &ListNode{
	// 				Val: 4, Next: &ListNode{Val: 5},
	// 			},
	// 		},
	// 	}},
	// 	{Val: 999, Next: &ListNode{Val: 1000}},
	// }
	// mergedList := mergeKLists(lists)
	// node := mergedList
	// fmt.Println("final list:")
	// for {
	// 	if node == nil {
	// 		break
	// 	}
	// 	fmt.Print(node.Val, " ")
	// 	node = node.Next
	// }
}

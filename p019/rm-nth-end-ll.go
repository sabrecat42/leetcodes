package main

import "fmt"

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func buildLIst(list []int) *ListNode {
	if len(list) == 0 {
		return nil
	}
	head := &ListNode{
		Val:  list[0],
		Next: nil,
	}
	node := head
	for i := 1; i < len(list); i++ {
		node.Next = &ListNode{
			Val:  list[i],
			Next: nil,
		}
		node = node.Next
	}
	return head
}

func printLinkedList(head *ListNode) {
	node := head
	if head == nil {
		fmt.Println("<empty_ll>")
		return
	}
	// i:=0
	for {
		if node == nil {
			break
		}
		fmt.Print(node.Val, " ")
		node = node.Next
	}
	fmt.Println("")
}

func recFunc(node *ListNode, n, idx int) (ll_len int) {
	if node.Next == nil {
		return idx
	}
	ll_len = recFunc(node.Next, n, idx+1)
	if n == ll_len-idx {
		node.Next = node.Next.Next
	}
	return
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	ll_len := recFunc(head, n, 1)
	// fmt.Println("ll_len=", ll_len)
	if n == ll_len {
		return head.Next
	}
	return head
}

func main() {
	// ll := buildLIst([]int{1, 2, 3, 4, 5})
	ll := buildLIst([]int{1})
	n := 1
	fmt.Println("Input:")
	printLinkedList(ll)
	fmt.Println("n=", n)
	fmt.Println("")

	ll = removeNthFromEnd(ll, n)

	fmt.Println("Output:")
	printLinkedList(ll)
}

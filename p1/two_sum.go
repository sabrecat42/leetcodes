package main

import "fmt"

// func twoSum(nums []int, target int) []int {
// 	for i := 0; i < len(nums); i++ {
// 		for j := i + 1; j < len(nums); j++ {
// 			if nums[i]+nums[j] == target {
// 				return []int{i, j}
// 			}
// 		}
// 	}
// 	return nil
// }

func twoSum(nums []int, target int) []int {
	var compl_map = make(map[int]int)
	for i := 0; i < len(nums); i++ {
		j, ok := compl_map[nums[i]]
		if ok {
			return []int{i, j}
		}
		compl_map[target-nums[i]] = i
	}
	return nil
}

func main() {
	var res = twoSum([]int{8, 2, 23, 1}, 9)
	fmt.Println(res)
	// fmt.(res[0],res[1]);
}

package main

import "fmt"

func twoSum(nums []int, target int) []int {
	for i := 0; i < len(nums); i++ {
		for j := i + 1; j < len(nums); j++ {
			if nums[i]+nums[j] == target {
				return []int{i, j}
			}
		}
	}
	return nil
}

func main() {
	var res = twoSum([]int{8, 2, 23, 1}, 9)
	fmt.Println(res)
	// fmt.(res[0],res[1]);
}

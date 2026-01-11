package main

import (
	"fmt"
)

func maxArea(h []int) (max_area int) {
	max_area = -1
	var h_len int = len(h)
	var i, j int = 0, h_len - 1
	var current_area int

	for {
		if i == j {
			break
		}
		if h[i] <= h[j] {
			current_area = (j - i) * h[i]
			i++
		} else {
			current_area = (j - i) * h[j]
			j--
		}
		if current_area > max_area {
			max_area = current_area
		}
	}
	return max_area
}

func main() {
	fmt.Println(maxArea([]int{1, 8, 6, 2, 5, 4, 8, 3, 7}))
}

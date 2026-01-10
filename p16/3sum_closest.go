package main

import (
	"fmt"
	"slices"
)

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// func threeSum(nums []int) (finalTriplets [][]int) {
func threeSumClosest(nums []int, target int) (best_sum int) {
	len_nums := len(nums)
	slices.Sort(nums)
	best_sum = nums[0] + nums[1] + nums[2]
	// fmt.Println("nums=", nums)
	// fmt.Println("target=", target)
	for i := 0; i < len_nums-2; i++ {
		// optimization
		max_val := (nums[i] + nums[len_nums-2] + nums[len_nums-1])
		min_val := (nums[i] + nums[i+1] + nums[i+2])
		if min_val > target && abs(target-min_val) >= abs(target-best_sum) {
			break
		}
		if max_val < target && abs(target-max_val) >= abs(target-best_sum) {
			continue
		}

		// fmt.Printf("\n\n")
		// fmt.Println("Current final_sum=", final_sum)
		// fmt.Println("i=", i, "num_i=", nums[i])
		if i > 0 && nums[i-1] == nums[i] {
			// fmt.Println("Skipping", nums[i], "because already seen")
			// fmt.Println("")
			continue
		}
		m, n := i+1, len_nums-1
		for {

			// fmt.Println("m=", m, "n=", n, "num_m=", nums[m], "num_n=", nums[n])
			if m >= n {
				// fmt.Println("m>=n -> break")
				break
			}
			if m > i+1 && nums[m] == nums[m-1] {
				m++
				// fmt.Println("n_m == n_m-1 -> break")
				continue
			}
			if n < len_nums-1 && nums[n] == nums[n+1] {
				n--
				// fmt.Println("n_n == n_n+1 -> break")
				continue
			}
			sum := nums[i] + nums[m] + nums[n]
			diffSumTarget := sum - target
			// fmt.Println("last_sum =", last_sum, "difflastsumtarget=", last_sum-target)
			// fmt.Println("sum =", sum, "diffSumTarget=", diffSumTarget)
			// TODO fix below
			// past this point diff of sum from target will only grow -> break out
			if abs(diffSumTarget) < abs(best_sum-target) {
				best_sum = sum
			}
			if diffSumTarget < 0 {
				// fmt.Println("sum-target to small -> m++")
				m++
			} else if diffSumTarget > 0 {
				// fmt.Println("sum-target to large -> n--")
				n--
			} else if sum == target {
				best_sum = sum
				// fmt.Println("numbers at idx", i, m, n, "sum exactly to target")
				return
			}
		}
	}
	// fmt.Println(len(finalTriplets))
	// fmt.Println(finalTriplets)
	return
}

func main() {
	// list := []int{-1, 0, 1, 2, -1, -4}
	// list := []int{0, 0, 0, 0}
	// list := []int{-4, -2, -2, -1, -1, 0, 1, 2, 5, 6, 6, 7}
	list := []int{13, 252, -87, -431, -148, 387, -290, 572, -311, -721, 222, 673, 538, 919, 483, -128, -518, 7, -36, -840, 233, -184, -541, 522, -162, 127, -935, -397, 761, 903, -217, 543, 906, -503, -826, -342, 599, -726, 960, -235, 436, -91, -511, -793, -658, -143, -524, -609, -728, -734, 273, -19, -10, 630, -294, -453, 149, -581, -405, 984, 154, -968, 623, -631, 384, -825, 308, 779, -7, 617, 221, 394, 151, -282, 472, 332, -5, -509, 611, -116, 113, 672, -497, -182, 307, -592, 925, 766, -62, 237, -8, 789, 318, -314, -792, -632, -781, 375, 939, -304, -149, 544, -742, 663, 484, 802, 616, 501, -269, -458, -763, -950, -390, -816, 683, -219, 381, 478, -129, 602, -931, 128, 502, 508, -565, -243, -695, -943, -987, -692, 346, -13, -225, -740, -441, -112, 658, 855, -531, 542, 839, 795, -664, 404, -844, -164, -709, 167, 953, -941, -848, 211, -75, 792, -208, 569, -647, -714, -76, -603, -852, -665, -897, -627, 123, -177, -35, -519, -241, -711, -74, 420, -2, -101, 715, 708, 256, -307, 466, -602, -636, 990, 857, 70, 590, -4, 610, -151, 196, -981, 385, -689, -617, 827, 360, -959, -289, 620, 933, -522, 597, -667, -882, 524, 181, -854, 275, -600, 453, -942, 134}

	// threeSum(list)
	fmt.Println(threeSumClosest(list, -2805))
	// fmt.Println(list[3])
	// fmt.Println(list[5])
	// fmt.Println(list[10])
}

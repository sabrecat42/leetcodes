package main

func maxArea(h []int) int {
	var max_area int = 0
	var h_len int = len(h)
	for i := 0; i < h_len-1; i++ {
		if ((h_len-1)-i)*h[i] >= max_area {
			for j := h_len - 1; j > i; j-- {
				// if largest possible area is already smaller than current max area -> skip
				if (j-i)*h[i] <= max_area {
					break
				}
				if h[i] > h[j] && (j-i)*h[j] > max_area {
					max_area = (j - i) * h[j]
				} else if h[i] <= h[j] && (j-i)*h[i] > max_area {
					max_area = (j - i) * h[i]
				}
			}
		}
	}
	return max_area
}

func main() {
	// fmt.Println(maxArea([]int{1, 8, 6, 2, 5, 4, 8, 3, 7}))
}

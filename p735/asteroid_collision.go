package main

import "fmt"

// Input: asteroids = [3,5,-6,2,-1,4]​​​​​​​
// Output: [-6,2,4]
// Explanation: The asteroid -6 makes the asteroid 3 and 5 explode, and then continues going left. On the other side, the asteroid 2 makes the asteroid -1 explode and then continues going right, without reaching asteroid 4.

func recCollision(stack []int, stack_ptr, asteroid int) ([]int, int) {
	if stack_ptr == -1 || stack[stack_ptr] < 0 || asteroid > 0 { // no collision
		stack[stack_ptr+1] = asteroid
		stack_ptr++
	} else if asteroid < 0 { // collision will happen
		if -asteroid > stack[stack_ptr] {
			stack_ptr--
			return recCollision(stack, stack_ptr, asteroid)
		}
		if -asteroid == stack[stack_ptr] {
			stack_ptr--
		}
	}
	return stack, stack_ptr
}

func asteroidCollision(asteroids []int) []int {
	stack := make([]int, len(asteroids))
	stack_ptr := -1
	for _, asteroid := range asteroids {
		stack, stack_ptr = recCollision(stack, stack_ptr, asteroid)
	}
	return stack[:stack_ptr+1]
}

func main() {
	// asteroids := []int{3, 5, -6, 2, -1, 4}
	asteroids := []int{10, 2, -5}
	fmt.Println(asteroidCollision(asteroids))
}

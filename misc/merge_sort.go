package main

import (
	"errors"
	"fmt"
	"log"
)

func merge(arr1, arr2 []int) ([]int, error) {
	len_arr1, len_arr2 := len(arr1), len(arr2)
	var result []int = make([]int, 0, len_arr1+len_arr2)
	i, i_h1, i_h2 := 0, 0, 0

	for {
		if i_h1 == len_arr1 || i_h2 == len_arr2 {
			break
		}
		if arr1[i_h1] < arr2[i_h2] {
			result = append(result, arr1[i_h1])
			i_h1++
		} else {
			result = append(result, arr2[i_h2])
			i_h2++
		}
		i++
	}

	// fmt.Println("	result after l39=", result)

	if i_h1 < len_arr1 && i_h2 < len_arr2 {
		return nil, errors.New("mergesort: both arr1 and arr2 have elements left")
	}

	result = append(result, arr1[i_h1:]...)
	result = append(result, arr2[i_h2:]...)

	// fmt.Println("	Sorted and returning: ", result)
	return result, nil
}

func mergeSort(arr []int) ([]int, error) {
	len_h := len(arr)
	if len_h == 1 {
		return arr, nil
	}
	mid_idx := len_h / 2
	left, err := mergeSort(arr[:mid_idx])
	right, err := mergeSort(arr[mid_idx:])
	if err != nil {
		return nil, err
	}
	return merge(left, right)
}

func main() {
	// sort idx's by length
	sorted_arr, err := mergeSort([]int{1, 8, 6, 2, 5, 4, 8, 3, 7})
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(sorted_arr)
}

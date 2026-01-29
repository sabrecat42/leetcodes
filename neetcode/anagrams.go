package main

import "fmt"

func groupAnagrams(strs []string) [][]string {
	len_strs := len(strs)
	lettersMap := make(map[[26]int][]string)
	for i := range len_strs {
		letterCountCard := [26]int{}
		for _, char := range strs[i] {
			letterCountCard[char-97]++
		}
		lettersMap[letterCountCard] = append(lettersMap[letterCountCard], strs[i])
	}
	finalList := [][]string{}
	for _, sublist := range lettersMap {
		finalList = append(finalList, sublist)
	}
	return finalList
}

func main() {
	// r1 := 'b'
	// fmt.Println(r1 - 97)
	res := groupAnagrams([]string{"act", "pots", "tops", "cat", "stop", "hat"})
	fmt.Println(res)
}

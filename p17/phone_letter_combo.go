package main

import (
	"fmt"
)

var digitLettersMap = map[rune]string{
	'2': "abc",
	'3': "def",
	'4': "ghi",
	'5': "jkl",
	'6': "mno",
	'7': "pqrs",
	'8': "tuv",
	'9': "wxyz",
}

func letterCombinations(digits string) []string {
	combos := []string{}
	// fmt.Println("digits=", digits)
	if len(digits) == 1 {
		for _, letter := range digitLettersMap[rune(digits[0])] {
			combos = append(combos, string(letter))
		}
		return combos
	}
	for _, letter := range digitLettersMap[rune(digits[0])] {
		for _, substring := range letterCombinations(digits[1:]) {
			// fmt.Println("to append =", letter, substring)
			combos = append(combos, (string(letter) + substring))
		}
	}
	return combos
}

func main() {
	fmt.Println(letterCombinations("3825"))
}

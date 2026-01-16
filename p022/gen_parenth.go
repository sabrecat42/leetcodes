package main

import (
	"fmt"
)

// recursive method. start from list of previous smaller n combinations.
// for each larger n: for range i to n start with "(" then move the ")" tp right by i (so with each iteration a larger amount of pairs of parantheses fit within "(...)" and fewer after the ")...").
// for all combos that fit between the braces "(...)" combine with all possible combos that fit after the ")..."

func recGenParaenth(n int, prevParenthCombos [][]string) []string {
	currentParenthCombos := make(map[string]bool)
	// fmt.Println("")
	// fmt.Println("working with:", len(prevParenthCombos))
	for i := 0; i < len(prevParenthCombos); i++ {
		// fmt.Println("i=", i)
		for _, prevLeftCombo := range prevParenthCombos[i] {
			leftPart := "(" + prevLeftCombo + ")"
			// fmt.Println("left part=", leftPart)
			for _, prevRightCombo := range prevParenthCombos[len(prevParenthCombos)-1-i] {
				// fmt.Println("right part=", prevRightCombo)
				currentCombo := leftPart + prevRightCombo
				// fmt.Println("final=", currentCombo)
				currentParenthCombos[currentCombo] = true
			}
		}
	}
	currentParenthList := []string{}
	for k := range currentParenthCombos {
		currentParenthList = append(currentParenthList, k)
	}
	if len(prevParenthCombos) == n {
		return currentParenthList
	}
	prevParenthCombos = append(prevParenthCombos, currentParenthList)
	return recGenParaenth(n, prevParenthCombos)
}

func generateParenthesis(n int) []string {
	if n == 1 {
		return []string{"()"}
	}
	parenthCombos := [][]string{{""}, {"()"}}
	return recGenParaenth(n, parenthCombos)
}

func main() {
	str := generateParenthesis(4)
	fmt.Println(str)
}

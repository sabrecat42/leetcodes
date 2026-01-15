package main

import (
	"fmt"
	"strings"
)

// 1:
// 		()
// 2:
//		(()), ()()
// 3:
//		((())), (()()), (())(), ()(()), ()()()

func recGenParaenth(n int, prevParenthCombos []string) []string {
	currentParenthCombos := make([]string, 0, len(prevParenthCombos)-1)
	for _, parenthCombo := range prevParenthCombos {
		currentParenthCombos = append(currentParenthCombos, ("(" + parenthCombo + ")"))
		currentParenthCombos = append(currentParenthCombos, ("()" + parenthCombo))
		if strings.ReplaceAll(parenthCombo, "()", "") != "" {
			currentParenthCombos = append(currentParenthCombos, (parenthCombo + "()"))
		}
	}
	prevParenthCombos = nil
	if n == 1 {
		return currentParenthCombos
	}
	return recGenParaenth(n-1, currentParenthCombos)
}

func generateParenthesis(n int) []string {
	parenthCombos := []string{"()"}
	if n == 1 {
		return parenthCombos
	}
	return recGenParaenth(n-1, parenthCombos)
}

func main() {
	str := generateParenthesis(4)
	fmt.Println(str)
}

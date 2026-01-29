package main

import (
	"strings"
)

func reverseWords(s string) string {
	var fields []string = strings.Fields(s)
	var result strings.Builder
	for i := len(fields) - 1; i >= 0; i-- {
		result.WriteString(fields[i])
		if i > 0 {
			result.WriteString(" ")
		}
	}
	return result.String()
}

func main() {
	s1 := "i am the    king   "
	// res := strings.Split(s1, " ")
	// res := strings.Fields(s1)
	// res := split(s1, 'm')
	// fmt.Println(res)
	res := reverseWords(s1)
	// fmt.Printf("%q\n", res)

}

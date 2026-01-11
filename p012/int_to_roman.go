package main

import "fmt"

func intToRoman(decimal int) (roman string) {
	// if decimal > 3999 || decimal < 1 {
	// 	fmt.Println("Cannot represent such int in roman")
	// 	return
	// }
	var romanNumerals = []string{"M", "D", "C", "L", "X", "V", "I"}

	var romIdx = 0

	for i := 1000; i > 0; i = i / 10 {
		currentDecVal := (decimal % (i * 10)) / i
		// fmt.Println("for i=", i, "got currentDecVal=", currentDecVal)
		// fmt.Println("current romanNumeral=", romanNumerals[romIdx])
		// fmt.Println("")
		if currentDecVal >= 1 && currentDecVal <= 3 {
			for {
				if currentDecVal < 1 {
					break
				}
				roman += romanNumerals[romIdx]
				currentDecVal--
			}
		} else if currentDecVal == 4 {
			roman += (romanNumerals[romIdx] + romanNumerals[romIdx-1])
		} else if currentDecVal >= 5 && currentDecVal <= 8 {
			roman += romanNumerals[romIdx-1]
			for {
				if currentDecVal < 6 {
					break
				}
				roman += romanNumerals[romIdx]
				currentDecVal--
			}
		} else if currentDecVal == 9 {
			roman += (romanNumerals[romIdx] + romanNumerals[romIdx-2])
		}
		romIdx += 2
	}

	return roman
}

func main() {
	var decNum int
	fmt.Scan(&decNum)
	fmt.Println(intToRoman(decNum))
}

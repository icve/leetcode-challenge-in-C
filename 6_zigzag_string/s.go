package main

import "strings"
import "fmt"

func convert(s string, numRows int) string {
	if len(s) == 0 {
		return ""
	}
	if len(s) == 1 {
		return s
	}
	if numRows == 1 {
		return s
	}
	initJumpLen := numRows*2 - 2
	numOfCycle := (len(s)-1)/initJumpLen + 1
	var rlt strings.Builder
	for i := 0; i < numOfCycle; i++ {
		rlt.WriteByte(s[i*initJumpLen])
	}
	forwardJumpLen := initJumpLen
	for i := 1; i <= numRows-2; i++ {
		forwardJumpLen -= 2
		remaining := (len(s) - i - 1)
		if remaining >= 0 {
			numOfCycle := remaining/(initJumpLen) + 1
			for j := 0; j < numOfCycle; j++ {
				idx := j*initJumpLen + i
				rlt.WriteByte(s[idx])
				if idx+forwardJumpLen < len(s) {
					rlt.WriteByte(s[idx+forwardJumpLen])
				}
			}
		}
	}
	remaining := (len(s) - (numRows - 1) - 1)
	if remaining >= 0 {
		numOfCycle = remaining/(initJumpLen) + 1
		for j := 0; j < numOfCycle; j++ {
			rlt.WriteByte(s[j*initJumpLen+numRows-1])
		}
	}

	return rlt.String()
}

func main() {
	s := "aB"
	fmt.Printf("%s\n", convert(s, 4))
}

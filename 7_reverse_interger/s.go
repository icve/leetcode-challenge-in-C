

import (
	"strconv"
	"math"
)

func reverse(x int) int {
	pfx := ""
	if x < 0 {
		pfx = "-"
	}
	s := strconv.Itoa(math.Abs(x))
	buf := []rune(s)
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		buf[i], buf[j] := buf[j], buf[i]
	}
	
}
package main
import (
		"math"
)
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	if len(nums1) > len(nums2){
		nums1, nums2 = nums2, nums1
	}
	
  l1 := len(nums1)
	l2 := len(nums2)
	l12 := l1 + l2

	start := 0
	end := l1 + 1
	even := (l1 + l2) % 2 == 0;
	for true{
	// start binary search on the shorter array
	// div1: divider 1
	/* 
	  div1 should have range of 0-l1 (inclusive)
	  div=0 means the the divider is place on the left of the 0(indexed) element.
	  div=l1 means the divier is place on the right of 
	  the last element (left of the non-existence after last)
	  it is also the count of the number of elements on the left of the divider
	*/
		div1 := (start + end) / 2
		// algebra equation : div1 + div2 == (l1 - div1) + (l2 - div2)
		div2 := (l12 - 2 * div1) / 2
		// greater of left
		gl := int(math.Max(arrGet(nums1, div1-1, math.Inf(-1)), arrGet(nums2, div2-1, math.Inf(-1))))
		// lease of right
		lr := int(math.Min(arrGet(nums1, div1, math.Inf(1)), arrGet(nums2, div2, math.Inf(1))))
		if gl <= lr{
			//desired position found
			if even{
				return float64(gl + lr)/2
			}
			return float64(lr)
		}
		// need to adjust cursor:
		if nums1[div1 - 1] != gl{
			// move right
			start = (start + end) / 2
		}else if outOfBound(nums1, div1) || nums1[div1] != lr{
			// move left
			end = (start + end) / 2

		}
	}
	return -1
}
func outOfBound(s []int, idx int) bool{
	return idx < 0 || idx >= len(s)
}
func arrGet(s []int, idx int, fallback float64) float64{
	if idx >=0 && idx < len(s){
		return float64(s[idx])
	}
	return fallback

}

/*
* some tests
* no overlapping 
[1, 2, 3], [4, 5]
* alternating increment
[1, 3, 5] [2, 4]
* left partial alternate
a := [] int {1, 3, 5, 6, 7, 8}
b := [] int{2, 4}
* surround
[3,4,5] [1, 10]
* center overlap
[1, 2, 3, 4] [3, 4, 5, 6]
* single
[42] [2]


*/
/*
func main(){
    // * no overlapping 
	// a := []int {1, 2, 3}
	// b := []int {4, 5}
    // * alternating increment
	// a := []int {1, 3, 5}
	// b := [] int{2, 4}
	// a := [] int {1, 3, 5, 6, 7, 8}
	// b := [] int{2, 4}
	//* left partial alternate
	//a := [] int {1, 3, 5, 6, 7, 8}
	//b := [] int{2, 4}
	// * surround
	// a := []int {3, 4 ,5} 
	// b := []int {1, 10}
	// * center overlap
	// a := []int {1, 2, 3, 4} 
	// b := []int {3, 4, 5, 6}
	// * single
	a := []int {42}
	b := []int {2}

	fmt.Println(findMedianSortedArrays(a, b))
}
*/
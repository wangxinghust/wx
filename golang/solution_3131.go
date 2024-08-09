package main

func addedInteger(nums1 []int, nums2 []int) int {
	max1 := 0
	max2 := 0
	for _, value := range nums1 {
		max1 = max(max1, value)
	}
	for _, value := range nums2 {
		max2 = max(max2, value)
	}
	return max2 - max1
}

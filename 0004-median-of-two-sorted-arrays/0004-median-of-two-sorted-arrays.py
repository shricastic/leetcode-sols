class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums1=sorted(nums1+nums2)
        l = len(nums1)-1
        
        if l%2 == 0:
            return nums1[l//2]
        else:
            return (nums1[l//2]+nums1[(l//2)+1])/2
        return 0
        
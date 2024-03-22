class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums1.extend(nums2)
        nums1.sort()
        
        si, ei = 0, len(nums1)-1
        mid = (si+ei)//2
        
        if ei%2 == 0:
            return nums1[mid]
        else:
            return (nums1[mid]+nums1[mid+1])/2
        
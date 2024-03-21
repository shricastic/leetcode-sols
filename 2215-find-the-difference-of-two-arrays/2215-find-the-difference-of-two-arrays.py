class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        ls1 = []
        ls2 = []
        
        for x in nums1:
            if x not in nums2 and x not in ls1:
                ls1.append(x)
        
        for x in nums2:
            if x not in nums1 and x not in ls2:
                ls2.append(x)
                
        return [ls1, ls2]
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        set1 = set(nums1)
        nums2 = set(nums2)
        res = []
        
        for i in nums2:
            if i in set1:
                res.append(i)
        return res
        
        
        
        
    
                
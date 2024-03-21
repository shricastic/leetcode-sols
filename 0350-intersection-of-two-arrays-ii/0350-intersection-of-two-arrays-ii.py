class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        newList = []
        nums_table = {}
        
        for x in nums1:
            nums_table[x] = nums_table.get(x,0) + 1
        
        for x in nums2:
            if x in nums_table and nums_table[x]>0:
                nums_table[x] = nums_table.get(x,0)-1
                newList.append(x)
        
        return newList;
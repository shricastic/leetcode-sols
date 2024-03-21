class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        count = {}
        for num in nums1:
            count[num] = count.get(num,0)+1
        
        temp = []
        for x in nums2:
            if x in count and count[x]>0:
                count[x] = count.get(x,0)-1
                temp.append(x)
                
        return temp
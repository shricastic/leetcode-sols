class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        res = [-1,-1]
        
        for num in range(len(nums)):
            if target == nums[num]:
                if res[0]==-1:
                    res[0]=num
                    res[1]=num
                else:
                    res[1]=num
        
        return res
                        
        
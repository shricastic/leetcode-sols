class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        fo, lo = -1, -1
        
        def first(x):
            nonlocal fo
            fi, li = 0, len(nums)-1
            
            while fi<=li:
                mid = (fi+li)//2
                
                if x<nums[mid]:
                    li=mid-1
                elif x>nums[mid]:
                    fi=mid+1
                else:
                    if fo==-1 or fo>mid:
                        fo=mid
                    li = mid-1
        
        def last(x):
            nonlocal lo
            fi, li = 0, len(nums)-1
            
            while fi<=li:
                mid = (fi+li)//2
                
                if x<nums[mid]:
                    li=mid-1
                elif x>nums[mid]:
                    fi=mid+1
                else:
                    if lo==-1 or lo<mid:
                        lo=mid
                    fi = mid+1
        
        first(target)
        last(target)
        
        return [fo, lo] 
            
            
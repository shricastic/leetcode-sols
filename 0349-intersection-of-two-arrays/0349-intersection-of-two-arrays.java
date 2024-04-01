class Solution {
    
    public static boolean binarySearch(int target, int[] nums){
        int si = 0;
        int ei = nums.length-1;
        
        while(si<=ei){
            int mid = (si+ei)/2;
            
            if(target<nums[mid]){
                ei = mid-1;
            } else if(target>nums[mid]){
                si = mid+1;
            } else{
                return true;
            }
            
        }
        
        return false;
    }
    
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set = new HashSet<>();
        Arrays.sort(nums2);
        
        for(int i : nums1){
            if(binarySearch(i,nums2)){
                set.add(i);
            }
        }
        
        int res[] = new int[set.size()];
        int j = 0;
        for(int i : set){
            res[j++] = i;
        }  
        return res;
    }
    
}
class Solution {
    public int removeDuplicates(int[] nums) {
        int cnt = 0;
        
        for(int i : nums){
            if(cnt<2 || nums[cnt-2]<i){
                nums[cnt]=i;
                cnt++;
            }
        }
        
        return cnt;
    }
}
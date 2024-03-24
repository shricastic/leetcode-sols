class Solution {
    public int findDuplicate(int[] nums) {
        boolean[] arr = new boolean[nums.length];
        
        for(int i : nums){
            if(arr[i]){
                return i;
            } else{
                arr[i] = true;
            }
        }
        return -1;
    }
}
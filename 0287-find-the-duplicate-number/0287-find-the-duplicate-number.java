class Solution {
    public int findDuplicate(int[] nums) {
        Set<Integer> st = new HashSet<>();
        
        for(int i : nums){
            if(st.add(i)){
                continue;
            } else{
                return i;
            }
        }
        return -1;
    }
}
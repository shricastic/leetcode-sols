class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        Set<Integer> set = new HashSet<>();
        List<Integer> lst = new ArrayList<>();
        
         for(int num: nums){
            if(set.contains(num)){
                lst.add(num);
            } else{
                set.add(num);                
            }
        }
        
        return lst;
    }
}
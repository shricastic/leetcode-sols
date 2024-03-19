import java.util.*;

class Solution {
    public int removeDuplicates(int[] nums) {
       int k = 0;
       if(nums.length==0){
       		return k;
       } 
       if(nums.length==1){
       		return k+1;
       }
       k=+1;
       int prev = nums[0];

       for(int i=1; i<nums.length ;i++){
       		if(nums[i] > prev){
       			prev = nums[i];
       			nums[k] = nums[i];
       			k++;
       		}
       }
       System.out.println(Arrays.toString(nums)+k);
       return k;
    }

    public static void main(String[] args) {
    	int[] nums = new int[]{0,0,1,1,1,2,2,3,3,4};

    	Solution s = new Solution();
    	s.removeDuplicates(nums);
    }
}
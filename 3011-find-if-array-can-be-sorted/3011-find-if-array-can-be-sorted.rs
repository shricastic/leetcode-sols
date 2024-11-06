impl Solution {
    pub fn sortable(num1: i32, num2: i32) -> bool{
        num1.count_ones() == num2.count_ones()
    }
    
    pub fn can_sort_array(mut nums: Vec<i32>) -> bool {
        let n = nums.len();
        
        for i in 0..n {
            for j in 0..n-i-1 {
                
                if nums[j] > nums[j+1] {
                    if Solution::sortable(nums[j], nums[j+1]){
                        nums.swap(j, j+1);
                    } else{
                        return false;
                    }
                }
            }
        }
        
        true
    }
}
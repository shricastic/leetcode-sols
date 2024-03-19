/*
 * @lc app=leetcode id=7 lang=java
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
    public int reverse(int x) {
        int revInt = 0;
        boolean negative = false;

        if(x<0){
            negative = true;
            x = Math.abs(x);
        }

        while(x>0){
            int lastDigit = x%10;
            x/=10;
            if (revInt > Integer.MAX_VALUE / 10) {
                return 0; 
            }
            revInt = revInt*10+lastDigit;
        }

        if(negative==true){
            revInt = -revInt;
        }

        return revInt;
    }
}
// @lc code=end


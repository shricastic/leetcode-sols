class Solution {
public:
    int reverse(int num){
        int res = 0;
        
        while(num>0){
            int ld = num%10;
            num /=10;
            
            
            if(res > (INT_MAX/10)+ld) return 0;
            
            res = (res*10)+ld;
        }
        
        return res;
    }
    
    bool isPalindrome(int x) {
        if(x<0) return false;
        
        int tmp = reverse(x);
        
        if(x-tmp==0){
            return true;
        }
    
        return false;
    }
};
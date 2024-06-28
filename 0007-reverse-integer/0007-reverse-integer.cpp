class Solution {
public:
    int reverse(int x) {
        int res = 0;
        bool negative = false;
        
        if(x<0){
            negative = true;
            x = abs(x);
        }
        
        while(x>0){
            int ld = x%10;
            x/=10;
            
            if(res > (INT_MAX-ld)/10) return 0;
            
            res = (res*10)+ld;
        }
        
        if(negative) return 0-res;
        return res;
    }
};
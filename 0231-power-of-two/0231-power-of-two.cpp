class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false; 
        
        for (int i = 0; ; i++) {
            long p = pow(2, i);
            if (p == n) return true;
            if (p > n) break; 
        }
        
        return false;
    }
};
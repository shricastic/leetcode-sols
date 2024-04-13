class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0; // Edge case: square root of 0 is 0

        long long res = 1; // Use long long to handle larger numbers
        for (long long i = 1; i <= x; ++i) {
            if (x < i * i) {
                return i - 1; // Return the floor square root
            }
            res = i; // Update res if i*i <= x
        }
        return res;
    }
};

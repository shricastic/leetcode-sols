class Solution {
private:
    bool isPrime(int n){
        if (n <= 1)
            return false;
        for (int i = 2; i*i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }
public:
    int nonSpecialCount(int l, int r) {
        int count = 0;
        int p=1;
        while(p*p<=r){
            if(p*p>=l && isPrime(p)) count++;
            p++;
        }
        return (r-l+1)-count;
    }
};
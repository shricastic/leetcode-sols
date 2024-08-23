class Solution {
private:
    int gcd(int a, int b){
        return b==0? a : gcd(b, a%b);
    }
    
public:
    string fractionAddition(string expression) {
        istringstream strm(expression);
        int num = 0, den = 1, n, d;
        char skip;
        
        while(strm >> n >> skip >> d){
            num = num*d + n*den;
            den *= d;
            
            int g =  gcd(num, den);
            num/=g; den/=g;
        }
        
        if (den < 0) { 
            num = -num;
            den = -den;
        }
        
        return to_string(num) +"/"+ to_string(den);
    }
};
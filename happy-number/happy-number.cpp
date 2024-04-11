class Solution {
private:
    unordered_set<int> set;
public:
    bool isHappy(int n) {
        if(n==1){
            return true;
        }
        
        int res = 0;
        
        while(n>0){
            int ld = n%10;
            res += ld*ld;
            n-=ld;
            n/=10;
        }
        
        if(set.contains(res)){
            return false;
        } else{
            set.insert(res);
        }
        
        
        return isHappy(res);
    }
};

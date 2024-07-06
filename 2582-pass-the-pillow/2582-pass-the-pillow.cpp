class Solution {
public:
    int passThePillow(int n, int time) {
        int res = 1;
        bool flag = false;
        
        while(time>0){
            if(res == n && flag == false) flag = true;
            if(res == 1 && flag == true)  flag = false;
            
            if(flag == false) res++;
            if(flag == true) res--;
            
            time--;
        }
        
        return res;
    }
};
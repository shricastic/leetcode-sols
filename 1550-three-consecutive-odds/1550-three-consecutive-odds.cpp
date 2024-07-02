class Solution {
public:
    bool isOdd(int n){
        if(n%2 != 0) return true;
        return false;
    }
    
    bool threeConsecutiveOdds(vector<int>& arr) {
        int si=0;
        
        for(int i=0 ; i<arr.size() ; i++){
            if(isOdd(arr[i])){
                if(i-si>=2) return true;
            } else{
                si = i+1;
            }  
        }
        
        return false;
    }
};
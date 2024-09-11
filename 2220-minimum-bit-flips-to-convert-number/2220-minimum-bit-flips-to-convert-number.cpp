class Solution {
private:
    string decimalToBin(int num){
        string bin = "";
        
        while(num>0){
            bin += (num%2 == 0? '0' : '1');
            num /= 2;
        }
        
        reverse(bin.begin(), bin.end());
        return bin;        
    }
    
public:
    int minBitFlips(int start, int goal) {
        string s1 = decimalToBin(start), s2 = decimalToBin(goal);
        
        while(s1.size()<s2.size()) s1 = "0" + s1;
        while(s1.size()>s2.size()) s2 = "0" + s2;
        
        int cnt = 0;
        
        for(int i=s1.size()-1 ; i>=0 ; i--) if(s1[i]!=s2[i]) cnt++;
        
        return cnt;
    }
};
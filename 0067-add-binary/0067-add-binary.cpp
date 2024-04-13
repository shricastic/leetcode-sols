class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int c=0, ia=a.size()-1, ib = b.size()-1;
        
        while(ia>=0 || ib>=0){
            int sum = c;
            if(ia>=0) sum+= a[ia]-'0';
            if(ib>=0) sum+= b[ib]-'0';
            
            res = to_string(sum%2)+res;
            c = sum/2;
            
            ia--;
            ib--;
        }
        
        if(c!=0) res = '1'+res;
        return res;
        
    }
};
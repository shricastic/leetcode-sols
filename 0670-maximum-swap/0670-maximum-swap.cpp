class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<int> li(10, -1);
        
        for(int i=0 ; i<s.size() ; i++) li[s[i]-'0'] = i;
        
        for(int i=0 ; i<s.size() ; i++){
            for(int j=9 ; j> s[i]-'0' ; j--){
                if(li[j] > i){
                    swap(s[li[j]], s[i]);
                    return stoi(s);
                }
            }
        }
        
        return num;
    }
};
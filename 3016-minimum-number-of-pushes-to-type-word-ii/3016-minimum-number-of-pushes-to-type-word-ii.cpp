class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cmap(26, 0);
        int res = 0, cnt=0;
        
        for(char c : word) cmap[c-97]++;
        sort(cmap.rbegin(), cmap.rend());
        
        for(int i : cmap){
            if(i>0){
                cout<< i << " ";
                res += i* ((cnt/8)+1);
                cnt++;
            }
        }
        
        return res;
    }
};
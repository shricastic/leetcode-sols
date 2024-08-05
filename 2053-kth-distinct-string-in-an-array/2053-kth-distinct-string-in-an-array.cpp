class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> map;
        
        for(string s : arr){
            if(map.count(s)>0){
                map[s]++;
            } else{
                map[s] = 1;
            }
        }
        
        for(string s : arr){
            if(map[s] == 1){
                if(k==1) return s;
                k--;
            }
        }
        
        return "";
    }
};
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map;
        vector<string> res;
        int min = -1;
        
        for(int i=0 ; i<list2.size() ; i++){
            map[list2[i]] = i;
        }
        
        for(int i=0 ; i<list1.size() ; i++){
            if(map.contains(list1[i])){
                int cnt = i + map[list1[i]];
                if(min==-1) min = cnt;
                if(cnt<min){ 
                    res.clear();
                    min = cnt;
                }
                
                if(i+map[list1[i]] == min){
                    res.push_back(list1[i]);
                }
                
            }
        }
        
        return res;
    }
};
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) { 
        vector<string> res;
        int n = names.size();
        
        while(res.size()!=n){
            int max = 0, idx = 0;
            
            for(int i = 0 ; i<names.size() ; i++){
                if(max<heights[i]){
                    max = heights[i];
                    idx = i;
                }
            }
            
            res.push_back(names[idx]);
            names.erase(names.begin()+idx);
            heights.erase(heights.begin()+idx);
        }
    
        return res;
    }
};
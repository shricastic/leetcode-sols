class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) { 
        vector<int> ht = heights;
        sort(ht.begin(), ht.end(), greater<int>());
        
        int maxht = *max_element(heights.begin(), heights.end());
        
        vector<string> intmap(maxht+1);
        
        for(int i=0 ; i<heights.size() ; i++){
            intmap[heights[i]] = names[i];
        }
        
        vector<string> res;
        
        for(int height : ht){
            res.push_back(intmap[height]);
        }
        
        return res;
    }
};
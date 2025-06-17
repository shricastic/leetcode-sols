class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
       sort(in.begin(), in.end());
       vector<vector<int>> res;
       int f = in[0][0], s = in[0][1];
       for(int i=1 ; i<in.size() ; i++){
            int f1 = in[i][0], s1 = in[i][1];
            if(f1<=s){
                if(s1>s) s = s1;
            } else{
                res.push_back({f, s});
                f = f1, s = s1;
            }
       }
       res.push_back({f, s});

       return res;
    }
};
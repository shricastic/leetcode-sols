class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        sort(in.begin(), in.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1]; 
        });


        int cnt = 0, prevEnd = in[0][1];

        for(int i=1 ; i<in.size() ; i++){
            if(in[i][0] < prevEnd){
                cnt++;
            } else {
                prevEnd = in[i][1];
            }
        }

        return cnt;
    }
};
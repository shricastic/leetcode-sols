class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> score;
        
        for(string op : operations){
            if(op == "C"){
                if(score.size()>0) score.pop_back();
            } else if(op == "+"){
                if(score.size()>=2){
                  int l = score[score.size()-1], sl = score[score.size()-2];                                                 score.push_back(l+sl);
                } 
            } else if(op == "D"){
                if(score.size()>0) {
                    int l = (int) score[score.size()-1];
                    score.push_back(l*2);
                }
            } else{
                int tmp = stoi(op);
                score.push_back(tmp);
            }
        }
        
        int res = 0;
        for(int points : score) res += points;
        
        return res;
    }
};
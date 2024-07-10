class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> score;
        
        for(string op : operations){
            if(op == "C"){
                if(score.size()>0) score.pop_back();
            } else if(op == "+"){
                if(score.size()>=2) score.push_back(score[score.size()-1] + score[score.size()-2]);
                
            } else if(op == "D"){
                if(score.size()>0) score.push_back(score[score.size()-1]*2);
            } else{
                score.push_back(stoi(op));
            }
        }
    
        return accumulate(score.begin(), score.end(), 0);
    }
};
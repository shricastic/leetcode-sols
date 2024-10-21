class Solution {
private:
    unordered_set<string> ust;
    int maxCnt;
    void rec(int i,int cnt,string &s){
        if(cnt + (s.size() - i) <= maxCnt) return;
        if(i == s.size()){
            maxCnt = max(maxCnt,cnt);
            return;
        }

        string substr;
        for(int j=i+1; j<=s.size(); j++){    
            substr = s.substr(i,j-i);
            if(ust.find(substr) == ust.end()){
                ust.insert(substr);
                rec(j,cnt+1,s);
                ust.erase(substr);
            }
        }
    }
public:
    int maxUniqueSplit(string s) {
        ust.clear();
        maxCnt = 0;
        rec(0,0,s);
        return maxCnt;
    }
};
class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wl) {
        int m = bw.size(), n = ew.size(), res=1;
        if(m != n) return 0;

        queue<string> q;
        set<string> set(wl.begin(), wl.end());
        if(!set.contains(ew)) return 0;
        q.push(bw);

        while(!q.empty()){
            int lsize = q.size();
            
            while(lsize--){
                string cw = q.front(); q.pop();
    
                for(int i=0 ; i<n ; i++){
                    string nw = cw;
                    for(char c='a' ; c<='z' ; c++){
                        nw[i] = c;
                        if(nw == ew) return res+1;
                        
                        if(set.contains(nw)){
                            q.push(nw); set.erase(nw);
                        }
                    }
                }
            }

            res++;
        } 

        return 0;
    }
};
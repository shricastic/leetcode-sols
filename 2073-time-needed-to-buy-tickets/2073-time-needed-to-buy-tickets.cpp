class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int cnt = 0;
        int idx = 0;
        
        while(tickets[k]!=0){
            if(tickets[idx]>0){
                cnt++;
                tickets[idx]--;
                idx = (idx+1) % tickets.size();
            } else{
                idx = (idx+1) % tickets.size();
            }
        }
        
        return cnt;
        
    }
};
class Solution:
    def countSeniors(self, details: List[str]) -> int:
        cnt = 0
        
        for people in details:
            if(int(people[11:13]) > 60): 
                cnt = cnt+1
        
        return cnt
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int maxLen = 0; 
        boolean present[] = new boolean[128];
        int li = 0;
        
        for(int ri=0 ; ri<s.length() ; ri++){
            char curr = s.charAt(ri);
            
            while(present[curr]){
                present[s.charAt(li)] = false;
                li++;
            }
            
            present[curr] = true;
            maxLen = Math.max(maxLen , ri-li+1);            
        }
        
        return maxLen;
        
    }
}
class Solution {
    public String reverseWords(String s) {
        s = s.trim();
        String[] arr = s.split("\\s+");
        
        int si = 0;
        int ei = arr.length-1;
        
        while(si<ei){
            String tmp = arr[si];
            arr[si] = arr[ei];
            arr[ei] = tmp;
            si++;
            ei--;
        }
        
        return String.join(" ", arr);
    }
}
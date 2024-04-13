class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> tmp = arr;
        int i=0, ia=0;
        
        while(i<tmp.size() && ia<arr.size()){
            if(tmp[i]==0){
                arr[ia] = 0;
                ia++;
                if(ia<arr.size()){
                    arr[ia] = 0;
                    ia++;
                }
                i++;
            } else{
                arr[ia] = tmp[i];
                ia++;
                i++;
            }
        }
        
        
    }
};
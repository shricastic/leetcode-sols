class NumArray {
private:
    vector<int> nums;
    vector<int> sum;
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
    }
    
    int sumRange(int left, int right) {
        if(sum.size()==0) calculateSum();
        return left == 0 ? sum[right] : sum[right] - sum[left - 1];
    }

    void calculateSum(){
        int curSum = 0; 
        for(int i=0; i<nums.size() ; i++){
            curSum += nums[i];
            sum.push_back(curSum);
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
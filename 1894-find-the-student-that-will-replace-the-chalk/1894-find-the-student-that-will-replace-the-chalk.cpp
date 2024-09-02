class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = accumulate(begin(chalk), end(chalk), 0l);
        while(k>=sum) k -= sum;
        for (int i = 0; i < chalk.size(); ++i)
            if ((k -= chalk[i]) < 0)
                return i;
        return 0;       
    }
};
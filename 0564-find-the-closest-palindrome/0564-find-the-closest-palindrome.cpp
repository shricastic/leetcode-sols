class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        long long num = stoll(n);
        
        if (num <= 10) return to_string(num - 1);
        if (num == 11) return "9";

        vector<long long> candidates;
        
        long long prefix = stoll(n.substr(0, (len + 1) / 2));
        for (int i = -1; i <= 1; ++i) {
            string p = to_string(prefix + i);
            string palin = p + string(p.rbegin() + (len % 2), p.rend());
            candidates.push_back(stoll(palin));
        }
        
        candidates.push_back((long long)pow(10, len - 1) - 1); 
        candidates.push_back((long long)pow(10, len) + 1);     
        
        long long closest = -1, minDiff = LLONG_MAX;
        for (long long candidate : candidates) {
            if (candidate == num) continue; 
            long long diff = abs(candidate - num);
            if (diff < minDiff || (diff == minDiff && candidate < closest)) {
                minDiff = diff;
                closest = candidate;
            }
        }
        
        return to_string(closest);
    }
};

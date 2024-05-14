#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> scoreIndexPairs;

        for (int i = 0; i < n; ++i) {
            scoreIndexPairs.push_back({score[i], i});
        }

        sort(scoreIndexPairs.begin(), scoreIndexPairs.end(), greater<pair<int, int>>());

        vector<string> res(n);
        vector<string> rank = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        // Assign ranks
        for (int i = 0; i < n; ++i) {
            if (i < 3) {
                res[scoreIndexPairs[i].second] = rank[i];
            } else {
                res[scoreIndexPairs[i].second] = to_string(i + 1);
            }
        }

        return res;
    }
};

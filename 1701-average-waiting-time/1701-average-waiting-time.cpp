#include <vector>

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int c = customers.size();
        long long waitTime = 0;
        long long currTime = 0;
        
        for (int i = 0; i < c; ++i) {
            
            if (currTime < customers[i][0]) currTime = customers[i][0];
             
            waitTime += (currTime + customers[i][1]) - customers[i][0];

            currTime += customers[i][1];
        }
        
        return (double) waitTime / c;
    }
};

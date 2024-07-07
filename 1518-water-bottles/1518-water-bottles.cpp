class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drunkBottles = numBottles;

        while (numBottles >= numExchange) {
            drunkBottles += numBottles / numExchange;
            numBottles = (numBottles / numExchange) + (numBottles % numExchange);
        }

        return drunkBottles;
    }
};

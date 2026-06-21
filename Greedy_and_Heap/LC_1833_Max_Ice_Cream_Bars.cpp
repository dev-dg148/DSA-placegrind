/*
 * Problem: Maximum Ice Cream Bars (LeetCode 1833)
 * Concept: Greedy + Sorting
 * TC: O(N log N) - Dominates due to sorting.
 * SC: O(1) or O(log N) - Depending on sorting algorithm used internally.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
      
        sort(costs.begin(), costs.end());
        
        int count = 0;
        
        for (int i = 0; i < costs.size(); i++) {
           
            if (costs[i] <= coins) {
                coins -= costs[i]; // Deduct the cost from our wallet
                count++;           // Increment the ice cream count
            } else {
               
                break;
            }
        }
        
        return count;
    }
};
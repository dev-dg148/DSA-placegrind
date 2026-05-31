/*
 * Problem: Final Value of Variable After Performing Operations (LeetCode 2011)
 * Concept: Array, Strings
 * Time Complexity: O(N) - Where N is the number of operations
 * Space Complexity: O(1) - Constant space used
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        
      
        for (int i = 0; i < operations.size(); i++) {
           
            if (operations[i][1] == '+') {
                x++;
            } else {
               
                x--;
            }
        }
        
        return x;
    }
};
/*
 * Problem: Lemonade Change (LeetCode 860)
 * Concept: Greedy Algorithm
 * Time Complexity: O(N) - Single pass through the bills array, where N is the number of customers.
 * Space Complexity: O(1) - Constant space used, only two integer variables tracking $5 and $10 counts.
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;  
        
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                
                fives++;
            } 
            else if (bills[i] == 10) {
              
                if (fives > 0) {
                    fives--;
                    tens++;
                } else {
                    return false;
                }
            } 
            else if (bills[i] == 20) {
                
                if (tens > 0 && fives > 0) {
                    tens--;
                    fives--;
                } 
               
                else if (fives >= 3) {
                    fives -= 3;
                } 
                
                else {
                    return false; 
                }
            }
        }
        
        return true; 
    }
};
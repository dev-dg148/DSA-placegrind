/*
 * Problem: LC 3751 - Total Waviness of Numbers in Range I
 * Concept: String Simulation, Flat Sliding Window (Size 3)
 * Time Complexity: O(N * D) 
 * Space Complexity: O(D) for string conversion
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int wavi(int num) {
        string s = to_string(num);
        if (s.length() < 3) return 0;

        int w = 0;
        
        for (int i = 1; i < s.length() - 1; i++) {
            char prev = s[i - 1];
            char curr = s[i];
            char next = s[i + 1];

            
            if ((curr > prev && curr > next) || (curr < prev && curr < next)) {
                w++;
            }
        }
        return w;
    }

    int totalWaviness(int num1, int num2) {
        int w = 0;
        for (int i = num1; i <= num2; i++) {
            w += wavi(i);
        }
        return w;
    }
};
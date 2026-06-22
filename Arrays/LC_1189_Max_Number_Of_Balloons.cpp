/*
 * Problem: Maximum Number of Balloons (LeetCode 1189)
 * Concept: Hashing / Frequency Array
 * TC: $O(N)$ - Where N is the length of the string, iterating through the text once.
 * SC: $O(1)$ - Constant space of size 26 for the frequency array.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[26] = {0};
        
        
        for (char s : text) {
            freq[s - 'a']++;
        }
        
        
        int balloon = INT_MAX;
        
        
        balloon = min(freq['b' - 'a'], balloon);
        balloon = min(freq['a' - 'a'], balloon);
        balloon = min(freq['l' - 'a'] / 2, balloon);
        balloon = min(freq['o' - 'a'] / 2, balloon);
        balloon = min(freq['n' - 'a'], balloon);

        return balloon;
    }
};
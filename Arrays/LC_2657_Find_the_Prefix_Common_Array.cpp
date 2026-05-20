/*
 * Problem: Find the Prefix Common Array of Two Arrays (LeetCode 2657)
 * Concept: Frequency Array / Hashing
 * Time Complexity: O(N) - Single pass through both arrays
 * Space Complexity: O(N) - Frequency array of size N + 1
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> freq(A.size() + 1, 0);
        vector<int> C(A.size());
        int count = 0;
        
        for (int i = 0; i < A.size(); i++) {
           
            freq[A[i]]++;
            if (freq[A[i]] == 2)
                count++;
                
           
            freq[B[i]]++;
            if (freq[B[i]] == 2)
                count++;
                
            
            C[i] = count;
        }
        return C;
    }
};
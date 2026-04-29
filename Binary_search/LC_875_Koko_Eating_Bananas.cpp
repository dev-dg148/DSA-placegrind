/*
 * Problem: Koko Eating Bananas (LeetCode 875)
 * Concept: Binary Search on Answers
 * Time Complexity: O(N * log(max(P)))
 * Space Complexity: O(1)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long checkh(vector<int>& piles, int mid) {
        long long sum = 0;
        for (int i = 0; i < piles.size(); i++) {
            sum = sum + (piles[i] + mid - 1) / mid;
        }
        return sum;
    }
    
    int minEatingSpeed(vector<int>& piles, int hr) {
        int l = 1, h = *max_element(piles.begin(), piles.end()), ans = -1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (checkh(piles, mid) <= hr) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};